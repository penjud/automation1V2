import os
import logging
from flask import Flask, send_file, jsonify
from flumine import Flumine, clients
from bkstrat import FlatKashModel, FlatIggyModel
from betfairlightweight import APIClient
from betfairlightweight.filters import streaming_market_filter
from dotenv import load_dotenv
from flask_cors import CORS
from betfairlightweight import exceptions as bf_exceptions
import threading
import requests
from flask import request

# Load environment variables
load_dotenv()

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', filename='server.log', filemode='w')
logger = logging.getLogger(__name__)

app = Flask(__name__)
CORS(app)

# Initialize the Betfair API client for non-interactive login
betfair_client = APIClient(username=os.getenv("BETFAIR_USERNAME"),
                           password=os.getenv("BETFAIR_PASSWORD"),
                           app_key=os.getenv("BETFAIR_APP_KEY"),
                           certs=os.getenv('BETFAIR_CERT_PATH'))

# Initialize the Flumine framework with the Betfair client
flumine_client = clients.BetfairClient(betfair_client)
framework = Flumine(client=flumine_client)

# Define the strategies
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
    global is_running, bot_thread
    if not is_running:
        bot_thread = threading.Thread(target=bot_logic)
        bot_thread.start()
        return True
    else:
        logger.info("Bot is already running.")
        return False

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
    try:
        start_bot()  # Ensure this function is robust and logs detailed errors
        return "Bot started successfully", 200
    except Exception as e:
        logger.error(f"Error starting bot: {e}", exc_info=True)
        return f"Error starting bot: {str(e)}", 500


@app.route("/stop", methods=["POST"])
def stop_bot_endpoint():
    try:
        stop_bot()
        return "Bot stopped successfully", 200
    except Exception as e:
        logger.error(f"Error stopping bot: {e}")
        return f"Error stopping bot: {str(e)}", 500

navigation_url = "https://example.com"  # Replace with the actual navigation URL
cert_file = "path/to/cert_file.pem"  # Replace with the actual path to the certificate file
key_file = "path/to/key_file.pem"  # Replace with the actual path to the key file

@app.route('/api/check-connection', methods=['GET'])
def check_connection():
    try:
        betfair_client.login()  # Non-interactive login
        betfair_client.logout()
        return jsonify({'connected': True}), 200
    except bf_exceptions.BetfairError as e:
        logger.error(f"Connection check failed: {e}", exc_info=True)
        return jsonify({'connected': False, 'error': str(e)}), 500

@app.route('/api/account-funds', methods=['GET'])
def get_account_funds():
    try:
        # Ensure that the client is logged in before making the request
        betfair_client.login()
        account_funds = betfair_client.account.get_account_funds()
        betfair_client.logout()
        
        # Convert account funds to a serializable format if needed
        # (Assuming account_funds is already serializable, or you have a method to do so)
        return jsonify(account_funds), 200
    except bf_exceptions.BetfairError as e:
        logger.error("Error retrieving account funds: {}".format(e), exc_info=True)
        return jsonify({'error': str(e)}), 500

@app.route('/api/races', methods=['GET'])
def get_races():
    event_type_id = request.args.get('eventTypeId')
    country_code = request.args.get('countryCode')

    url = f'{navigation_url}{event_type_id}/{country_code}'
    print(f'Making API request to: {url}')  # Log the API request URL

    response = requests.get(url, cert=(cert_file, key_file))

    if response.status_code == 200:
        data = response.json()
        print(f'API response data: {data}')  # Log the API response data
        return jsonify(data)
    else:
        print(f'API request failed with status code: {response.status_code}')  # Log the error status code
        return jsonify({'error': 'Failed to fetch races'}), 500

if __name__ == "__main__":
    logger.info("Starting the server...")
    app.run(host='0.0.0.0', port=5000)
    logger.info("Server stopped.")