import os
import logging
from flask import Flask, send_file, jsonify
from flumine import Flumine, clients
from bkstrat import FlatKashModel, FlatIggyModel
from betfairlightweight import APIClient
from betfairlightweight.filters import streaming_market_filter
from dotenv import load_dotenv
from flask_cors import CORS
import threading
import requests
from flask import request
from betfair_client import BetfairClient
from datetime import datetime
import betfairlightweight.exceptions

# Load environment variables
load_dotenv()

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', filename='server.log', filemode='w')
logger = logging.getLogger(__name__)

app = Flask(__name__)
CORS(app)

betfair_client = BetfairClient(
    username=os.getenv("BETFAIR_USERNAME"),
    password=os.getenv("BETFAIR_PASSWORD"),
    app_key=os.getenv("BETFAIR_APP_KEY"),
    certs_dir=os.getenv("BETFAIR_CERT_PATH")
)

flumine_client = clients.BetfairClient(betfair_client)
framework = Flumine(client=flumine_client)

thoroughbreds_strategy = FlatKashModel(
    market_filter=streaming_market_filter(
        event_type_ids=["7"],  # Horse Racing
        country_codes=["AU"],  # Australian Markets
        market_types=["WIN"],  # Win Markets
    ),
    max_order_exposure=50,
    max_trade_count=1,
    max_live_trade_count=1,
)

greyhounds_strategy = FlatIggyModel(
    market_filter=streaming_market_filter(
        event_type_ids=["4339"],  # Greyhound Racing
        country_codes=["AU"],  # Australian Markets
        market_types=["WIN"],  # Win Markets
    ),
    max_order_exposure=50,
    max_trade_count=1,
    max_live_trade_count=1,
)
is_running = False
bot_thread = None

def bot_logic():
    global is_running
    logger.info("Starting the betting bot.")
    is_running = True
    try:
        framework.run()  # Assuming this needs to run continuously
    except Exception as e:
        logger.error("An error occurred while running the betting bot: {}".format(e), exc_info=True)
    finally:
        is_running = False

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
        is_running = True
        threading.Thread(target=start_bot).start()
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
        # Directly obtain the account funds balance as a float.
        account_funds_balance = betfair_client.get_account_funds()
        # Return the balance in the expected JSON format.
        return jsonify({'available_to_bet_balance': account_funds_balance})
    except Exception as e:
        logging.error('Error fetching account funds:', exc_info=True)
        return jsonify({'error': 'Failed to retrieve account funds'}), 500
    
@app.route('/api/races', methods=['GET'])
def get_races():
    event_type_id = request.args.get('eventTypeId')
    country_code = request.args.get('countryCode')
    market_count = request.args.get('marketCount', default=10, type=int)  # Default to 10 markets if not provided
    
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
    event_type_id = request.args.get('eventTypeId')
    market_count = request.args.get('marketCount', default=10, type=int)  # Default to 10 markets if not provided

    races = betfair_client.get_races_for_date(event_type_id, market_count)
    if races:
        processed_races = []
        for race in races:
            race_details = {
                'event_id': race.event.id,
                'event_name': race.event.name,
                'market_start_time': race.market_start_time.strftime('%Y-%m-%d %H:%M:%S'),
                'market_count': len(race.market_ids)
            }
            processed_races.append(race_details)
        return jsonify(processed_races), 200
    else:
        return jsonify({'error': 'Failed to retrieve races for date'}), 500
    
@app.route('/api/formatted-races', methods=['GET'])
def get_formatted_races():
    country_code = request.args.get('countryCode')
    event_type_id = request.args.get('eventTypeId')
    market_count = request.args.get('marketCount', default=10, type=int)
    selected_date = request.args.get('date')

    # Log the input parameters
    logger.info(f"Fetching races for country_code: {country_code}, event_type_id: {event_type_id}, market_count: {market_count}, selected_date: {selected_date}")

    # Convert the selected date to the desired format
    selected_date = datetime.strptime(selected_date, '%Y-%m-%d').strftime('%Y-%m-%dT%H:%M:%SZ')

    races = betfair_client.get_races_for_date(event_type_id, market_count, country_code, selected_date)
    if races:
        formatted_races = []
        for race in races:
            race_details = {
                'event_id': race.event.id,
                'event_name': race.event.name,
                'market_start_time': race.market_start_time.strftime('%Y-%m-%d %H:%M:%S'),
                'market_count': len(race.market_ids)
            }
            formatted_races.append(race_details)
        # Log the formatted races before returning
        logger.info(f"Formatted races: {formatted_races}")
        return jsonify(formatted_races), 200
    else:
        logger.error("Failed to retrieve races")
        return jsonify({'error': 'Failed to retrieve races'}), 500

if __name__ == "__main__":
    logger.info("Starting the server...")
    app.run(host='0.0.0.0', port=5000)
    logger.info("Server stopped.")