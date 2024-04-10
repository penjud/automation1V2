import psycopg2

db_params = {
    'dbname': 'sickpunt',
    'user': 'penjud',
    'password': '#18Hoppy70',
    'host': 'localhost'
}
create_tables_commands = [
"""
CREATE TABLE sports (
    sport_id SERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL
);
""",
"""
    CREATE TABLE events (
    event_id SERIAL PRIMARY KEY,
    sport_id INTEGER REFERENCES sports(sport_id),
    name VARCHAR(255) NOT NULL,
    start_time TIMESTAMP WITHOUT TIME ZONE NOT NULL,
    venue VARCHAR(255)
);
    """,
"""
    CREATE TABLE markets (
    market_id SERIAL PRIMARY KEY,
    event_id INTEGER REFERENCES events(event_id),
    market_name VARCHAR(255) NOT NULL,
    market_type VARCHAR(255) NOT NULL,
    market_time TIMESTAMP WITHOUT TIME ZONE NOT NULL,
    market_status VARCHAR(50) NOT NULL,
    number_of_winners INTEGER,
    number_of_active_runners INTEGER,
    bet_delay INTEGER,
    bsp_reconciled BOOLEAN,
    complete BOOLEAN,
    in_play BOOLEAN,
    cross_matching BOOLEAN,
    runners_voidable BOOLEAN,
    turn_in_play_enabled BOOLEAN,
    version INTEGER
);
    """,
"""
    CREATE TABLE runners (
    runner_id SERIAL PRIMARY KEY,
    market_id INTEGER REFERENCES markets(market_id),
    selection_id INTEGER,
    runner_name VARCHAR(255) NOT NULL,
    handicap DOUBLE PRECISION,
    status VARCHAR(50) NOT NULL,
    sort_priority INTEGER,
    last_traded_price DOUBLE PRECISION,
    total_matched DOUBLE PRECISION,
    adjustment_factor DOUBLE PRECISION,
    removal_date TIMESTAMP WITHOUT TIME ZONE
);
    """,
"""
CREATE TABLE users (
    user_id SERIAL PRIMARY KEY,
    username VARCHAR(255) UNIQUE NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    api_key VARCHAR(255),
    session_token VARCHAR(255)
);
    """,
"""
CREATE TABLE user_ip_whitelist (
    whitelist_id SERIAL PRIMARY KEY,
    user_id INTEGER REFERENCES users(user_id),
    ip_address VARCHAR(255) NOT NULL
);
    """,
"""
CREATE TABLE bets (
    bet_id SERIAL PRIMARY KEY,
    user_id INTEGER REFERENCES users(user_id),
    market_id INTEGER REFERENCES markets(market_id),
    runner_id INTEGER REFERENCES runners(runner_id),
    stake DECIMAL(18, 2) NOT NULL,
    price DECIMAL(18, 2) NOT NULL,
    placed_at TIMESTAMP WITHOUT TIME ZONE NOT NULL,
    outcome VARCHAR(50)
);
    """,
"""
CREATE TABLE market_changes (
    change_id SERIAL PRIMARY KEY,
    market_id INTEGER REFERENCES markets(market_id),
    published_time TIMESTAMP WITHOUT TIME ZONE NOT NULL,
    change_type VARCHAR(50) NOT NULL
);
    """,
"""
CREATE TABLE price_volume_data (
    data_id SERIAL PRIMARY KEY,
    runner_id INTEGER REFERENCES runners(runner_id),
    market_id INTEGER REFERENCES markets(market_id),
    price DOUBLE PRECISION NOT NULL,
    volume DOUBLE PRECISION NOT NULL,
    time_recorded TIMESTAMP WITHOUT TIME ZONE NOT NULL
);
    """,
"""
CREATE TABLE historical_data (
    historical_id SERIAL PRIMARY KEY,
    market_id INTEGER REFERENCES markets(market_id),
    event_id INTEGER REFERENCES events(event_id),
    data TEXT NOT NULL,
    captured_at TIMESTAMP WITHOUT TIME ZONE NOT NULL
);
    """,
"""
CREATE TABLE additional_data (
    additional_data_id SERIAL PRIMARY KEY,
    event_id INTEGER REFERENCES events(event_id),
    data_type VARCHAR(255) NOT NULL,
    value TEXT NOT NULL
);
    """,
"""
CREATE TABLE betfair_api_usage (
    usage_id SERIAL PRIMARY KEY,
    user_id INTEGER REFERENCES users(user_id),
    api_key VARCHAR(255),
    operation VARCHAR(255) NOT NULL,
    timestamp TIMESTAMP WITHOUT TIME ZONE NOT NULL
);
    """
]
def create_tables():
    conn = None
    try:
        conn = psycopg2.connect(**db_params)
        cur = conn.cursor()
        for command in create_tables_commands:
            cur.execute(command)
        conn.commit()
        cur.close()
    except (Exception, psycopg2.DatabaseError) as error:
        print("Error while creating tables:", error)
    finally:
        if conn is not None:
            conn.close()

if __name__ == '__main__':
    create_tables()