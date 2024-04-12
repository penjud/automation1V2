import requests
import logging
import psycopg2
from psycopg2.extras import RealDictCursor
from flumine_bf_client import FlumineBetfairClient

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

SERVER_URL = 'http://localhost:5000'  # Update with the actual server URL if hosted elsewhere


class Database:
    def __init__(self, db_params):
        self.conn = psycopg2.connect(**db_params)

    def get_sports(self):
        with self.conn.cursor(cursor_factory=RealDictCursor) as cursor:
            cursor.execute("SELECT * FROM sports")
            return cursor.fetchall()

    def add_sport(self, name):
        with self.conn.cursor() as cursor:
            cursor.execute("INSERT INTO sports (name) VALUES (%s)", (name,))
            self.conn.commit()

    def close(self):
        self.conn.close()

# Usage
db_params = {
    'dbname': 'sickpunt',
    'user': 'penjud',
    'password': '#18Hoppy70',
    'host': 'localhost'
}

db = Database(db_params)
print(db.get_sports())
db.add_sport('New Sport')
db.close()

def start_bot():
    url = f"{SERVER_URL}/start"
    try:
        response = requests.post(url)
        if response.status_code == 200:
            logger.info("Bot started successfully via server.")
        else:
            logger.error(f"Failed to start bot: {response.status_code} {response.text}")
    except requests.exceptions.RequestException as e:
        logger.exception(f"An error occurred while starting the bot: {e}")

def stop_bot():
    url = f"{SERVER_URL}/stop"
    try:
        response = requests.post(url)
        if response.status_code == 200:
            logger.info("Bot stopped successfully via server.")
        else:
            logger.error(f"Failed to stop bot: {response.status_code} {response.text}")
    except requests.exceptions.RequestException as e:
        logger.exception(f"An error occurred while stopping the bot: {e}")

if __name__ == "__main__":
    logger.info("Main application starting.")
    start_bot()
    # stop_bot() could be called here or triggered by some condition/event in your application
    logger.info("Main application running. Use Ctrl+C to stop.")
