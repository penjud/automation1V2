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
from auth import auth_bp
from models import Strategy, User
from flask import Blueprint

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

# Define utility functions
upload_directory = "/home/penjud/vscode_projects/automation1V2/uploads"  # Replace with the actual path to the upload directory

def save_file(file):
    # Generate a unique filename for the uploaded file
    filename = file.filename
    unique_filename = f"{int(time.time())}_{filename}"
    app.register_blueprint(registrations_bp)
    file_path = os.path.join(upload_directory, unique_filename)
    file.save(file_path)
    
    return file_path

def start_bot():
    global is_running, framework
    while is_running:
        try:
            framework.run()
        except Exception as e:
            app.logger.error(f"Error in bot logic: {e}")
            is_running = False

def stop_bot():
    global is_running, bot_thread
    if is_running:
        app.logger.info("Stopping the betting bot.")
        is_running = False
        if bot_thread:
            bot_thread.join()
            bot_thread = None
        return True
    else:
        app.logger.info("Bot is not running.")
        return False

# Define route handlers
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
        app.logger.error('Error fetching account funds:', exc_info=True)
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
        app.logger.error(f"Error saving strategy: {e}")
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
        app.logger.error(f"Error deleting strategy: {e}")
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
        app.logger.error(f"Error loading strategy: {e}")
        return jsonify({'error': 'Failed to load strategy'}), 500

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
    
    return jsonify({'message': 'Profile updated successfully', 'success': True})

def create_app():
    app = Flask(__name__)
    app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql://penjud:#18Hoppy70@localhost/sickpunt'
    db.init_app(app)
    # Other configurations and initializations
    return app
# Define the registrations_bp blueprint
registrations_bp = Blueprint('registrations', __name__)

if __name__ == "__main__":
    with app.app_context():
        db.create_all()
    app = create_app()
    with app.app_context():
        db.create_all()
    app.logger.info("Starting the server...")
    app.register_blueprint(auth_bp)
    app.register_blueprint(registrations_bp)  # Register the registrations_bp blueprint
    app.register_blueprint(registrations_bp)
    app.run(host='0.0.0.0', port=5000)
    app.logger.info("Server stopped.")