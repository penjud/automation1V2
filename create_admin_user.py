from extensions import db
from models import User
from server import app

def create_admin_user():
    # Explicitly initialize db with app
    db.init_app(app)

    with app.app_context():
        # Check if an admin user already exists
        admin_user = User.query.filter_by(is_admin=True).first()
        if not admin_user:
            # Create a new admin user
            admin_user = User(username='admin', email='admin@example.com', is_admin=True)
            admin_user.set_password('your_admin_password')
            db.session.add(admin_user)
            db.session.commit()
            print("Admin user created successfully.")
        else:
            print("Admin user already exists.")

if __name__ == '__main__':
    create_admin_user()