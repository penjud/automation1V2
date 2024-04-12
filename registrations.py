# registrations.py

from flask import Blueprint, request, jsonify
from models import User, db
registration_bp = Blueprint('registration', __name__)

@registration_bp.route('/api/register', methods=['POST'])

class User(db.Model):
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
    def register():
        data = request.get_json()  # Retrieve JSON data from the request object
        username = data.get('username')  # Define the "username" variable
        password = data.get('password')
        email = data.get('email')
        new_user = User(username=username, email=email)
        new_user.set_password(password) # Hash the password

        db.session.add(new_user)
        db.session.commit()

        return jsonify({'message': 'User registered successfully'}), 201

    registration_bp.add_url_rule('/api/register', view_func=register, methods=['POST'])
