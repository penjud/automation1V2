import os
import betfairlightweight
from dotenv import load_dotenv
import logging

# Load environment variables and set up logging
load_dotenv()
logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)

_betfair_client = None

class BetfairClient:
    def __init__(self, username, password, app_key, certs_dir):
        self.client = betfairlightweight.APIClient(username, password, app_key, certs_dir)
        self.session_token = self.client.login()

    def is_token_valid(self):
        try:
            self.client.keep_alive()  # Keep alive to check if the token is still valid
            return True
        except betfairlightweight.exceptions.APIError as e:
            if "INVALID_SESSION_INFORMATION" in str(e):
                logger.info("Session token expired or invalid, refreshing...")
                return False
            raise  # Re-raise the exception for other API errors

    def refresh_session_token(self):
        self.client.logout()
        self.session_token = self.client.login()

    def get_account_funds(self):
        if not self.is_token_valid():
            self.refresh_session_token()
        try:
            account_info = self.client.account.get_account_funds()
            return account_info.available_to_bet_balance
        except Exception as e:
            logger.error(f"Failed to retrieve account funds: {e}")
            return None

def get_betfair_client():
    global _betfair_client
    if _betfair_client is None:
        try:
            username = os.getenv('BETFAIR_USERNAME')
            password = os.getenv('BETFAIR_PASSWORD')  
            app_key = os.getenv('BETFAIR_APP_KEY')
            certs_dir = os.getenv('BETFAIR_CERT_PATH')

            _betfair_client = BetfairClient(username, password, app_key, certs_dir)
            logger.info("Betfair client successfully logged in.")
        except Exception as e:
            logger.error(f"Failed to initialize Betfair client: {e}")
            _betfair_client = None

    return _betfair_client
