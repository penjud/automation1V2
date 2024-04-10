import psycopg2

class Database:
    def __init__(self, db_params):
        try:
            self.conn = psycopg2.connect(**db_params)
            print("Database connection established.")
        except psycopg2.OperationalError as e:
            print(f"Error connecting to the database: {e}")
            self.conn = None

    def get_sports(self):
        if self.conn:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT * FROM sports")
                return cursor.fetchall()
        return []

    def add_sport(self, name):
        if self.conn:
            with self.conn.cursor() as cursor:
                cursor.execute("INSERT INTO sports (name) VALUES (%s)", (name,))
                self.conn.commit()
                print(f"Added '{name}' to the sports table.")

    def close(self):
        if self.conn:
            self.conn.close()

if __name__ == '__main__':
    db_params = {
        'dbname': 'sickpunt',
        'user': 'penjud',
        'password': '#18Hoppy70',
        'host': 'localhost'
    }

    db = Database(db_params)
    sports = db.get_sports()
    print("Sports in the database:", sports)

    sport_name = 'Test Sport'
    if any(sport['name'] == sport_name for sport in sports):
        print(f"Sport '{sport_name}' already exists.")
    else:
        print(f"Adding a new sport: {sport_name}")
        db.add_sport(sport_name)

    db.close()
