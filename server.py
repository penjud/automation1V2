import os
import logging
from datetime import datetime
from flask import Flask, request, jsonify, send_from_directory
from flumine import Flumine, clients
from bkstrat import FlatKashModel, FlatIggyModel
from betfair_client import BetfairClient
from betfairlightweight.filters import streaming_market_filter
from dotenv import load_dotenv
from flask_cors import CORS
import threading
import json
from flask import make_response

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', filename='server.log', filemode='w')
logger = logging.getLogger(__name__)

app = Flask(__name__)
CORS(app, resources={r'/*': {'origins': '*'}})

# Load environment variables
load_dotenv()

betfair_client = BetfairClient(
    username=os.getenv("BETFAIR_USERNAME"),
    password=os.getenv("BETFAIR_PASSWORD"),
    app_key=os.getenv("BETFAIR_APP_KEY"),
    certs_dir=os.getenv("BETFAIR_CERT_PATH")
)

flumine_client = clients.BetfairClient(betfair_client)
framework = Flumine(client=flumine_client)

strategies = {
    "FlatKashModel": FlatKashModel(
        market_filter=streaming_market_filter(
            event_type_ids=["7"], # Horse Racing
            country_codes=["AU"], # Australian Markets
            market_types=["WIN"], # Win Markets
        ),
        max_order_exposure=50,
        max_trade_count=1,
        max_live_trade_count=1,
    ),
    "FlatIggyModel": FlatIggyModel(
        market_filter=streaming_market_filter(
            event_type_ids=["4339"], # Greyhound Racing
            country_codes=["AU"], # Australian Markets
            market_types=["WIN"], # Win Markets
        ),
        max_order_exposure=50,
        max_trade_count=1,
        max_live_trade_count=1,
    )
}

is_running = False
bot_thread = None

def start_bot():
    global is_running
    while is_running:
        try:
            framework.run()
        except Exception as e:
            logger.error(f"Error in bot logic: {e}")
            is_running = False

def stop_bot():
    global is_running
    if is_running:
        logger.info("Stopping the betting bot.")
        is_running = False
        if bot_thread:
            bot_thread.join()
        return True
    else:
        logger.info("Bot is not running.")
        return False

@app.route("/start", methods=["POST"])
def start_bot_endpoint():
    global is_running
    if not is_running:
        is_running = True
        threading.Thread(target=start_bot).start()
        return "Bot started successfully", 200
    else:
        return "Bot is already running", 200

@app.route("/stop", methods=["POST"])
def stop_bot_endpoint():
    global is_running
    if is_running:
        if stop_bot():
            return "Bot stopped successfully", 200
        else:
            return "Failed to stop the bot", 500
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
        logging.error('Error fetching account funds:', exc_info=True)
        return jsonify({'error': 'Failed to retrieve account funds'}), 500

@app.route('/')
def home():
    return app.send_static_file('index.html')

@app.route('/strategies')
def strategies_page():
    return send_from_directory('static', 'strategies.html')

@app.route('/api/save-strategy-to-file', methods=['POST'])
def save_strategy_to_file():
    try:
        data = request.get_json()
        strategy_name = data['strategyName']
        strategy_settings = data['strategySettings']
        
        file_path = f"strategies/{strategy_name}.json"
        with open(file_path, 'w') as file:
            json.dump(strategy_settings, file)
        
        response = make_response(jsonify({'message': 'Strategy saved successfully'}))
        response.headers['Content-Type'] = 'application/json'
        return response
    except Exception as e:
        logger.error(f"Error saving strategy: {e}")
        response = make_response(jsonify({'error': 'Failed to save strategy'}), 500)
        response.headers['Content-Type'] = 'application/json'
        return response

@app.route('/api/load-strategy-from-file')
def load_strategy_from_file():
    strategy_name = request.args.get('strategyName')
    file_path = f"strategies/{strategy_name}.json"
    
    if os.path.exists(file_path):
        with open(file_path, 'r') as file:
            strategy_settings = json.load(file)
        return jsonify(strategy_settings)
    else:
        return jsonify({'message': 'Strategy not found'})

@app.route('/api/delete-strategy-file', methods=['DELETE'])
def delete_strategy_file():
    strategy_name = request.args.get('strategyName')
    file_path = f"strategies/{strategy_name}.json"
    
    if os.path.exists(file_path):
        os.remove(file_path)
        return jsonify({'message': 'Strategy deleted successfully'})
    else:
        return jsonify({'message': 'Strategy not found'})

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
    logger.info(f"Fetching races for country_code: {country_code}, event_type_id: {event_type_id}, market_count: {market_count}, selected_date: {selected_date}")
    try:
        selected_date = datetime.strptime(selected_date, '%Y-%m-%d').strftime('%Y-%m-%dT%H:%M:%SZ')
        races = betfair_client.get_races_for_date(event_type_id, market_count, country_code, selected_date)
        if races:
            formatted_races = [{'event_id': race.get('event_id'), 'event_name': race.get('event_name'), 'market_start_time': race.get('market_start_time'), 'market_count': len(race.get('market_ids', []))} for race in races]
            logger.info(f"Races data structure: {races[0] if races else 'No races found'}")
            return jsonify(formatted_races), 200
        else:
            logger.warning("No races found")
            return jsonify({'message': 'No races found'}), 404
    except Exception as e:
        logger.exception("Failed to retrieve races")
        return jsonify({'error': 'Failed to retrieve races'}), 500

if __name__ == "__main__":
    logger.info("Starting the server...")
    app.run(host='0.0.0.0', port=5000)
    logger.info("Server stopped.")
