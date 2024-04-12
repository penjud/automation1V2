import os
import threading
import json
import secrets
import time
from datetime import datetime
from flask import Flask, request, jsonify, send_from_directory
from flask_cors import CORS
from flask_login import LoginManager, login_user, current_user
from logging.handlers import RotatingFileHandler
import logging
from extensions import db
from flumine_bf_client import FlumineBetfairClient
from betfair_client import BetfairClient
from flumine import Flumine, clients, BaseStrategy
from flumine.order.trade import Trade
from flumine.order.ordertype import LimitOrder
from flumine.exceptions import FlumineException
from dotenv import load_dotenv
from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy

# Initialize Flask application
app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = os.getenv('DATABASE_URI', 'sqlite:///fallback.db')
db.init_app(app)

migrate = Migrate(app, db)
CORS(app, resources={r'/*': {'origins': '*'}})

# Setup logging
log_file_path = os.path.join(os.path.abspath(os.path.dirname(__file__)), 'server.log')
file_handler = RotatingFileHandler(log_file_path, maxBytes=1024 * 1024 * 100, backupCount=20)
file_handler.setLevel(logging.DEBUG)
file_formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
file_handler.setFormatter(file_formatter)
app.logger.addHandler(file_handler)

console_handler = logging.StreamHandler()
console_handler.setLevel(logging.DEBUG)
console_formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
console_handler.setFormatter(console_formatter)
app.logger.addHandler(console_handler)

app.logger.setLevel(logging.DEBUG)
app.logger.info("Logging is set up.")

# Load environment variables
load_dotenv()

from models import Strategy, User

# Initialize global variables for bot control
is_running = False
bot_thread = None

# Initialize Flumine client
betfair_client = FlumineBetfairClient(
    username=os.getenv("BETFAIR_USERNAME"),
    password=os.getenv("BETFAIR_PASSWORD"),
    app_key=os.getenv("BETFAIR_APP_KEY"),
    certs_dir=os.getenv("BETFAIR_CERT_PATH")
)
flumine_client = clients.BetfairClient(betfair_client)
framework = Flumine(client=flumine_client)

# Create a LoginManager instance
login_manager = LoginManager()
login_manager.init_app(app)

@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))

def save_file(file):
    # Generate a unique filename for the uploaded file
    filename = file.filename
    unique_filename = f"{int(time.time())}_{filename}"
    
    # Define the directory where the files will be saved
    upload_directory = 'uploads'
    
    # Create the upload directory if it doesn't exist
    if not os.path.exists(upload_directory):
        os.makedirs(upload_directory)
    
    # Save the file to the upload directory
    file_path = os.path.join(upload_directory, unique_filename)
    file.save(file_path)
    
    return file_path

def start_bot():
    global is_running, framework
    while is_running:
        try:
            framework.run()
        except Exception as e:
            logger.error(f"Error in bot logic: {e}")
            is_running = False
logger = logging.getLogger(__name__)


def stop_bot():
    global is_running, bot_thread
    if is_running:
        logger.info("Stopping the betting bot.")
        is_running = False
        if bot_thread:
            bot_thread.join()
            bot_thread = None
        return True
    else:
        logger.info("Bot is not running.")
        return False

@app.route("/start", methods=["POST"])

def start_bot_endpoint():
    global is_running, bot_thread
    if not is_running:
        is_running = True
        bot_thread = threading.Thread(target=start_bot)
        bot_thread.start()
        return "Bot started successfully", 200
    else:
        return "Bot is already running", 200

@app.route("/stop", methods=["POST"])

def stop_bot_endpoint():
    if stop_bot():
        return "Bot stopped successfully", 200
    else:
        return "Bot is not running", 200
    
def initialize_betfair_api(user):
    # Assuming you have a method to get the user's Betfair credentials
    username = user.username
    password = user.password # Make sure to securely handle and store passwords
    app_key = user.app_key
    certs_dir = user.certs_dir

    # Initialize Flumine with the Betfair client
    flumine = Flumine(client=FlumineBetfairClient(username, password, app_key, certs_dir))
    return flumine

def place_bet(user, market_id, selection_id, stake):
    flumine = initialize_betfair_api(user)
    
    # Define a simple strategy for placing a bet
    class PlaceBetStrategy(BaseStrategy):
        def check_market_book(self, market, market_book):
            # Place a bet if the market book is available
            if market_book.status != "OPEN":
                return

            # Example: Place a bet on the selection with the given stake
            trade = Trade(
                market_id=market_id,
                selection_id=selection_id,
                handicap=0, # Adjust based on your needs
                strategy=self
            )
            order = trade.create_order(
                side="BACK", # or "LAY"
                order_type=LimitOrder(stake, 1.01) # Example price
            )
            market.place_order(order)

    # Add the strategy to Flumine
    flumine.add_strategy(PlaceBetStrategy(), [market_id])

    # Start Flumine to place the bet
    try:
        flumine.run()
    except FlumineException as e:
        print(f"Failed to place bet: {e}")
    finally:
        flumine.stop()

@app.route('/bot-status', methods=['GET'])

def get_bot_status():
    return jsonify({'is_running': is_running})

@app.route('/api/check-connection', methods=['GET'])

def check_connection():
    connected = betfair_client.is_connected()
    return jsonify({'connected': connected})

@app.route('/api/account-funds', methods=['GET'])

def get_account_funds():
    try:
        account_funds_balance = betfair_client.get_account_funds()
        return jsonify({'available_to_bet_balance': account_funds_balance})
    except Exception as e:
        logger.error('Error fetching account funds:', exc_info=True)
        return jsonify({'error': 'Failed to retrieve account funds'}), 500

@app.route('/')

def home():
    return app.send_static_file('index.html')

@app.route('/strategies')

def strategies_page():
    return send_from_directory('static', 'strategies.html')

@app.route('/api/save-strategy', methods=['POST'])

def save_strategy():
    try:
        data = request.get_json()
        strategy_name = data['strategyName']
        strategy_settings = data['strategySettings']

        strategy = Strategy.query.filter_by(strategy_name=strategy_name).first()
        if strategy:
            strategy.strategy_settings = json.dumps(strategy_settings)
        else:
            new_strategy = Strategy(strategy_name=strategy_name, strategy_settings=json.dumps(strategy_settings))
            db.session.add(new_strategy)

        db.session.commit()
        return jsonify({'message': 'Strategy saved successfully'})
    except Exception as e:
        logger.error(f"Error saving strategy: {e}")
        return jsonify({'error': 'Failed to save strategy'}), 500

@app.route('/api/delete-strategy', methods=['DELETE'])

def delete_strategy():
    try:
        strategy_name = request.args.get('strategyName')
        strategy = Strategy.query.filter_by(strategy_name=strategy_name).first()
        if strategy:
            db.session.delete(strategy)
            db.session.commit()
            return jsonify({'message': 'Strategy deleted successfully'})
        else:
            return jsonify({'message': 'Strategy not found'}), 404
    except Exception as e:
        logger.error(f"Error deleting strategy: {e}")
        return jsonify({'error': 'Failed to delete strategy'}), 500

@app.route('/api/load-strategy', methods=['GET'])

def load_strategy():
    try:
        strategy_name = request.args.get('strategyName')
        strategy = Strategy.query.filter_by(strategy_name=strategy_name).first()
        if strategy:
            strategy_settings = json.loads(strategy.strategy_settings)
            return jsonify(strategy_settings)
        else:
            return jsonify({'message': 'Strategy not found'}), 404
    except Exception as e:
        logger.error(f"Error loading strategy: {e}")
        return jsonify({'error': 'Failed to load strategy'}), 500

def generate_session_token(user_id):
    """
    Generate a random session token for the given user ID.
    """
    # Combine the user ID with a random token and return it
    return f"{user_id}-{secrets.token_hex(16)}"

@app.route('/api/login', methods=['POST'])
def login():
    try:
        data = request.get_json()
        logger.debug("Login request data: %s", data)
        
        username = data.get('username')
        password = data.get('password')

        if not username or not password:
            logger.warning("Username or password missing in request")
            return jsonify({'message': 'Username or password missing'}), 400

        user = User.query.filter_by(username=username).first()

        if not user:
            logger.warning("User not found: %s", username)
            return jsonify({'message': 'User not found'}), 404

        if user.check_password(password):
            if request.remote_addr == user.whitelisted_ip:
                session_token = generate_session_token(user.id)
                login_user(user)
                
                logger.info("User authenticated successfully: %s", username)
                return jsonify({'success': True, 'message': 'Login successful', 'session_token': session_token}), 200
            else:
                logger.warning("Access denied for IP: %s", request.remote_addr)
                return jsonify({'success': False, 'message': 'Access denied. IP address not whitelisted.'}), 403
        else:
            logger.warning("Authentication failed for user: %s", username)
            return jsonify({'success': False, 'message': 'Invalid username or password.'}), 401

    except Exception as e:
        logger.error("Error during login: %s", str(e), exc_info=True)
        return jsonify({'success': False, 'message': 'An error occurred during login.'}), 500


@app.route('/api/races', methods=['GET'])

def get_races():
    event_type_id = request.args.get('eventTypeId')
    country_code = request.args.get('countryCode')
    market_count = request.args.get('marketCount', default=10, type=int)
    try:
        races = betfair_client.get_races_by_event_type_and_country(event_type_id, country_code, market_count)
        if races:
            return jsonify(races), 200
        else:
            return jsonify({'error': 'No races found'}), 404
    except Exception as e:
        logger.error(f"Error fetching races: {e}")
        return jsonify({'error': 'Failed to fetch races'}), 500

@app.route('/api/races-for-date', methods=['GET'])

def get_races_for_date():
    country_code = request.args.get('countryCode')
    event_type_id = request.args.get('eventTypeId')
    market_count = request.args.get('marketCount', default=10, type=int)
    selected_date = request.args.get('date')
    try:
        selected_date = datetime.strptime(selected_date, '%Y-%m-%d').strftime('%Y-%m-%dT%H:%M:%SZ')
        races = betfair_client.get_races_for_date(event_type_id, market_count, country_code, selected_date)
        if races:
            formatted_races = [{'event_id': race.get('event_id'), 'event_name': race.get('event_name'), 'market_start_time': race.get('market_start_time')} for race in races]
            return jsonify(formatted_races), 200
        else:
            return jsonify({'message': 'No races found'}), 404
    except Exception as e:
        logger.error("Failed to retrieve races")
        return jsonify({'error': 'Failed to retrieve races'}),

@app.route('/api/race-details', methods=['GET'])

def get_race_details():
    race_id = request.args.get('raceId')
    if not race_id:
        return jsonify({'error': 'No race ID provided'}), 400

    race_details = fetch_race_details_by_id(race_id)
    if race_details:
        return jsonify(race_details)
    else:
        return jsonify({'error': 'Race details not found'}), 404

def fetch_race_details_by_id(race_id):
    # Initialize the BetfairClient
    betfair_client = BetfairClient()
    
    # Use the BetfairClient to fetch market catalogues for the given race_id
    market_catalogues = betfair_client.list_market_catalogue({
        'eventIds': [race_id],
        'marketProjection': ['EVENT', 'MARKET_START_TIME'],
        'maxResults': '1'
    })


    if market_catalogues:
        # Assuming the first market catalogue contains the desired race information
        market_catalogue = market_catalogues[0]
        event = market_catalogue.get('event')

        if event:
            return {
                'event_name': event.get('name'),
                'market_start_time': event.get('openDate')
            }

    return {'error': 'Race details not found'}

@app.route('/api/profile', methods=['POST'])

def update_profile():
    api_key = request.form.get('apiKey')
    username = request.form.get('username')
    password = request.form.get('password')
    cert_file = request.files.get('certFile')
    key_file = request.files.get('keyFile')
    
    # Validate and store the API credentials in the database
    user = db.session.query(User).filter_by(id=current_user.id).first()
    user.betfair_api_key = api_key
    user.betfair_username = username
    user.betfair_password = password
    
    # Save the uploaded files to a designated directory
    cert_file_path = save_file(cert_file)
    key_file_path = save_file(key_file)
    
    # Update the user's profile with the file paths
    user.betfair_cert_file = cert_file_path
    user.betfair_key_file = key_file_path
    
    db.session.commit()
    
    return jsonify({
        'success': True
    })

if __name__ == "__main__":
    with app.app_context():
        db.create_all()
    app.logger.info("Starting the server...")
    app.run(host='0.0.0.0', port=5000)
    app.logger.info("Server stopped.")