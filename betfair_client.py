import os
import betfairlightweight
from dotenv import load_dotenv
import logging
import time
from betfairlightweight.filters import market_filter as MarketFilter
from datetime import datetime, timedelta

# Load environment variables and set up logging
load_dotenv()
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class BetfairClient:
    def __init__(self, username, password, app_key, certs_dir, session_timeout=3600):
        self.username = username
        self.client = betfairlightweight.APIClient(username, password, app_key, certs_dir)
        self.session_token = self.client.login()
        self.account = self.client.account
        self.betting = self.client.betting
        self.session_timeout = session_timeout
        self.session_start_time = time.time()
        
    def login(self):
        self.client.login()
        self.account = self.client.account
        self.betting = self.client.betting

    def is_token_valid(self):
        try:
            self.client.keep_alive()
            return True
        except betfairlightweight.exceptions.APIError as e:
            if "INVALID_SESSION_INFORMATION" in str(e):
                logger.info("Session token expired or invalid, refreshing...")
                return False
            raise

    def refresh_session_token(self):
        self.client.logout()
        self.session_token = self.client.login()
        self.session_start_time = time.time()

    @property
    def session_expired(self):
        current_time = time.time()
        elapsed_time = current_time - self.session_start_time
        return elapsed_time > self.session_timeout

    def ensure_session_valid(self):
        if self.session_expired:
            self.refresh_session_token()
            logger.info("Session refreshed successfully.")
        else:
            logger.info("Session is still valid.")

    def get_races_for_date(self, event_type_id, market_count, country_code, selected_date):
        try:
            market_filter = MarketFilter(
                event_type_ids=[event_type_id],
                market_start_time={
                    'from': selected_date,
                    'to': (datetime.strptime(selected_date, '%Y-%m-%dT%H:%M:%SZ') + timedelta(days=1)).strftime('%Y-%m-%dT%H:%M:%SZ')
                },
                market_countries=[country_code],
                market_type_codes=['WIN'],
                in_play_only=False
            )
            racing_events = self.betting.list_events(filter=market_filter)
            return racing_events[:market_count] if market_count else racing_events
        except Exception as e:
            logger.error(f"Failed to retrieve races for date: {e}")
            return None

    def get_account_details(self):
        try:
            return self.account.get_account_details()
        except Exception as e:
            logger.error(f"Failed to retrieve account details: {e}")
            return None

    def get_account_funds(self):
        try:
            account_info = self.account.get_account_funds()
            return account_info.available_to_bet_balance
        except Exception as e:
            logger.error(f"Failed to retrieve account funds: {e}")
            return None

def get_betfair_client():
    try:
        username = os.getenv('BETFAIR_USERNAME')
        password = os.getenv('BETFAIR_PASSWORD')
        app_key = os.getenv('BETFAIR_APP_KEY')
        certs_dir = os.getenv('BETFAIR_CERT_PATH')
        betfair_client = BetfairClient(username, password, app_key, certs_dir)
        logger.info("Betfair client successfully logged in.")
        return betfair_client
    except Exception as e:
        logger.error(f"Failed to initialize Betfair client: {e}")
        return None
