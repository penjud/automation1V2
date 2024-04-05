import requests
import logging

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

SERVER_URL = 'http://localhost:5000'  # Update with the actual server URL if hosted elsewhere

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
