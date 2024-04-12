import os
import threading
import json
import time
from flask import Flask, request, jsonify, send_from_directory, Blueprint
from flask_cors import CORS
from flask_login import LoginManager, UserMixin, login_user, logout_user, current_user
from logging.handlers import RotatingFileHandler
import logging
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from dotenv import load_dotenv

# Load environment variables
load_dotenv()

# Initialize Flask application
app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = os.getenv('DATABASE_URI', 'sqlite:///fallback.db')
app.config['SECRET_KEY'] = os.getenv('SECRET_KEY', 'your_secret_key')

# Setup database
db = SQLAlchemy(app)
migrate = Migrate(app, db)

# Setup CORS
CORS(app, resources={r'/*': {'origins': '*'}})

# Setup logging
log_file_path = os.path.join(os.path.dirname(__file__), 'server.log')
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

# Importing after initializing db to avoid circular imports
from flumine_bf_client import FlumineBetfairClient
from flumine import Flumine, clients

# Initialize Flumine client
betfair_client = FlumineBetfairClient(
    username=os.getenv("BETFAIR_USERNAME"),
    password=os.getenv("BETFAIR_PASSWORD"),
    app_key=os.getenv("BETFAIR_APP_KEY"),
    certs_dir=os.getenv("BETFAIR_CERT_PATH")
)
flumine_client = clients.BetfairClient(betfair_client)
framework = Flumine(client=flumine_client)

# Initialize LoginManager
login_manager = LoginManager()
login_manager.init_app(app)

@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))

# Define models
class User(db.Model, UserMixin):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False)
    password = db.Column(db.String(120), nullable=False)

# Define utility functions
def start_bot():
    global is_running, framework
    while is_running:
        try:
            framework.run()
        except Exception as e:
            app.logger.error(f"Error in bot logic: {e}")
            is_running = False

# Define routes
@app.route('/start', methods=["POST"])
def start_bot_endpoint():
    global is_running, bot_thread
    if not is_running:
        is_running = True
        bot_thread = threading.Thread(target=start_bot)
        bot_thread.start()
        return jsonify({"message": "Bot started successfully"}), 200
    else:
        return jsonify({"message": "Bot is already running"}), 200

@app.route('/stop', methods=["POST"])
def stop_bot_endpoint():
    global is_running, bot_thread
    if is_running:
        app.logger.info("Stopping the betting bot.")
        is_running = False
        if bot_thread:
            bot_thread.join()
            bot_thread = None
        return jsonify({"message": "Bot stopped successfully"}), 200
    else:
        return jsonify({"message": "Bot is not running"}), 200

@app.route('/')
def home():
    return send_from_directory('static', 'index.html')

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000)
