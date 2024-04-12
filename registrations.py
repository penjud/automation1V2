# registrations.py

from flask import Blueprint, request, jsonify
from models import User, db
from werkzeug.security import generate_password_hash

registration_bp = Blueprint('registration', __name__)

@registration_bp.route('/api/register', methods=['POST'])
def register():
    data = request.get_json()
    username = data.get('username')
    email = data.get('email')
    password = data.get('password')

    # Check if username or email already exists
    user_exists = User.query.filter(User.username == username).first() or User.query.filter(User.email == email).first()
    if user_exists:
        return jsonify({'message': 'Username or email already exists'}), 400

    # Create new user
    new_user = User(username=username, email=email)
    new_user.set_password(password) # Hash the password

    # Save the new user to the database
    db.session.add(new_user)
    db.session.commit()

    return jsonify({'message': 'User registered successfully'}), 201
