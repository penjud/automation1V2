import os
import betfairlightweight
from dotenv import load_dotenv
import logging
import time
from betfairlightweight.filters import market_filter as MarketFilter
from datetime import datetime, timedelta

load_dotenv()
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class FlumineBetfairClient:
    EXCHANGE = "BETFAIR"

    def __init__(self, username, password, app_key, certs_dir, session_timeout=3600):
        self.client = betfairlightweight.APIClient(username, password, app_key, certs_dir)
        self.session_token = self.client.login()
        self.account = self.client.account
        self.betting = self.client.betting
        self.session_timeout = session_timeout
        self.session_start_time = time.time()
        self.username = username

    def login(self):
        try:
            self.session_token = self.client.login()
            self.account = self.client.account
            self.betting = self.client.betting
            return True
        except betfairlightweight.exceptions.APIError as e:
            print(f"Failed to log in: {e}")
            return False

    def is_token_valid(self):
        try:
            self.client.keep_alive()
            return True
        except betfairlightweight.exceptions.APIError as e:
            if "INVALID_SESSION_INFORMATION" in str(e):
                logger.info("Session token expired or invalid, refreshing...")
                return False
            raise

    def is_connected(self):
        try:
            self.client.keep_alive()
            return True
        except betfairlightweight.exceptions.APIError as e:
            logger.error(f"API connection check failed: {e}")
            return False

    def keep_alive(self):
        try:
            self.client.keep_alive()
            return True
        except betfairlightweight.exceptions.APIError as e:
            logger.error(f"Failed to keep session alive: {e}")
            return False

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
        from_date_str = datetime.strptime(selected_date, '%Y-%m-%dT%H:%M:%SZ').strftime('%Y-%m-%dT%H:%M:%SZ')
        to_date_str = (datetime.strptime(selected_date, '%Y-%m-%dT%H:%M:%SZ') + timedelta(days=1)).strftime('%Y-%m-%dT%H:%M:%SZ')

        market_filter = MarketFilter(
            event_type_ids=[event_type_id],
            market_start_time={
                'from': from_date_str,
                'to': to_date_str
            },
            market_countries=[country_code],
            market_type_codes=['WIN'],
            in_play_only=False
        )

        racing_events = self.betting.list_events(filter=market_filter)
        event_details = []

        for event_result in racing_events[:market_count] if market_count else racing_events:
            detail = {
                'event_id': event_result.event.id,
                'event_name': event_result.event.name,
                'market_start_time': event_result.event.open_date.strftime('%Y-%m-%d %H:%M:%S')
            }
            event_details.append(detail)

        return event_details

    def get_account_funds(self):
        try:
            account_info = self.account.get_account_funds()
            return account_info.available_to_bet_balance
        except Exception as e:
            logger.error(f"Failed to retrieve account funds: {e}")
            return None

    def get_races_by_event_type_and_country(self, event_type_id, country_code, market_count):
        try:
            market_filter = MarketFilter(
                event_type_ids=[event_type_id],
                market_countries=[country_code],
                market_type_codes=['WIN'],
                in_play_only=False,
                market_count=market_count
            )

            racing_events = self.betting.list_events(filter=market_filter)
            return racing_events
        except Exception as e:
            logger.error(f"Failed to retrieve races: {e}")
            return None

    def fetch_race_details_by_id(self, race_id):
        market_catalogue = self.betting.list_market_catalogue(event_ids=[race_id])

        if market_catalogue:
            market = market_catalogue[0]
            event = market['event']
            return {
                'event_name': event['name'],
                'market_start_time': event['openDate'],
                'country_code': event.get('countryCode', 'Unknown'),
                'market_count': len(market['runners'])
            }
        
        return {'error': 'Race details not found'}

    def get_upcoming_race_ids(self):
        upcoming_races = self.betting.list_events(event_type_id='7')
        return [race['id'] for race in upcoming_races]

def get_betfair_client():
    try:
        username = os.getenv('BETFAIR_USERNAME')
        password = os.getenv('BETFAIR_PASSWORD')
        app_key = os.getenv('BETFAIR_APP_KEY')
        certs_dir = os.getenv('BETFAIR_CERT_PATH')
        return FlumineBetfairClient(username, password, app_key, certs_dir)
    except Exception as e:
        logger.error(f"Failed to initialize Betfair client: {e}")
        return None
