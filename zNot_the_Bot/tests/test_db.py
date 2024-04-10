from unittest.mock import MagicMock, patch
import sys
sys.path.append('/home/penjud/vscode_projects/automation1V2/tests')

from database import Database  
import sys

sys.path.append('database.py')
@patch('your_database_module.psycopg2.connect')

def test_get_sports(mock_connect):
    # Set up the mock connection and cursor
    mock_cursor = MagicMock()
    mock_connection = MagicMock()
    mock_connect.return_value = mock_connection
    mock_connection.cursor.return_value.__enter__.return_value = mock_cursor
    
    # Define what the mock cursor should return when executing a query
    mock_cursor.fetchall.return_value = [{'sport_id': 1, 'name': 'Soccer'}]
    
    # Call the function you are testing
    db = Database({'dbname': 'testdb', 'user': 'test', 'password': 'test', 'host': 'localhost'})
    sports = db.get_sports()
    
    # Assert that the results are as expected
    assert sports == [{'sport_id': 1, 'name': 'Soccer'}]
    # Ensure the query was executed
    mock_cursor.execute.assert_called_once_with("SELECT * FROM sports")
    
    # Close the database connection
    db.close()

@patch('your_database_module.psycopg2.connect')
def test_add_sport(mock_connect):
    mock_cursor = MagicMock()
    mock_connection = MagicMock()
    mock_connect.return_value = mock_connection
    mock_connection.cursor.return_value.__enter__.return_value = mock_cursor
    
    db = Database({'dbname': 'testdb', 'user': 'test', 'password': 'test', 'host': 'localhost'})
    db.add_sport('Test Sport')
    
    # Check if the execute method was called with the right SQL command
    mock_cursor.execute.assert_called_once_with("INSERT INTO sports (name) VALUES (%s)", ('Test Sport',))
    
    # Verify commit was called to save the transaction
    mock_connection.commit.assert_called_once()
    
    # Close the database connection
    db.close()