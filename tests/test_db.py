import psycopg2

db_params = {
    'dbname': 'sickpunt',
    'user': 'penjud',
    'password': '#18Hoppy70',
    'host': 'localhost'
}

try:
    conn = psycopg2.connect(**db_params)
    cur = conn.cursor()
    cur.execute("SELECT table_name FROM information_schema.tables WHERE table_schema = 'public'")
    tables = cur.fetchall()
    print("Tables in the database:")
    for table in tables:
        print(table[0])
    cur.close()
except Exception as e:
    print(f"An error occurred: {e}")
finally:
    if conn is not None:
        conn.close()
