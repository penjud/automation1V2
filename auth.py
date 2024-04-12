# auth.py
from flask import Blueprint, request, jsonify
from models import User
import logging
import secrets
from flask_login import login_user

auth_bp = Blueprint('auth', __name__)
logger = logging.getLogger(__name__)

def generate_session_token(user_id):
    """
    Generate a random session token for the given user ID.
    """
    # Combine the user ID with a random token and return it
    return f"{user_id}-{secrets.token_hex(16)}"

@auth_bp.route('/api/login', methods=['POST'])
def login():
    try:
        data = request.get_json()
        logger.debug("Login request data: %s", data)
        username = data.get('username')
        password = data.get('password')

        if not username or not password:
            logger.warning("Username or password missing in request")
            return jsonify({'message': 'Username or password missing'}), 400

        user = User.query.filter_by(username=username).first()

        if not user:
            logger.warning("User not found: %s", username)
            return jsonify({'message': 'User not found'}), 404

        if user and user.check_password(password):
            if user.whitelists and any(ip.ip_address == request.remote_addr for ip in user.whitelists):
                session_token = generate_session_token(user.id)
                login_user(user)
                
                logger.info("User authenticated successfully: %s", username)
                return jsonify({'success': True, 'message': 'Login successful', 'session_token': session_token}), 200
            else:
                logger.warning("Access denied for IP: %s", request.remote_addr)
                return jsonify({'success': False, 'message': 'Access denied. IP address not whitelisted.'}), 403
        else:
            logger.warning("Authentication failed for user: %s", username)
            return jsonify({'success': False, 'message': 'Invalid username or password.'}), 401

    except Exception as e:
        logger.error("Error during login: %s", str(e), exc_info=True)
        return jsonify({'success': False, 'message': 'An error occurred during login.'}), 500

