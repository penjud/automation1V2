import pytest
from flumine_bf_client import FlumineBetfairClient
import os

# Example of an Integration Test
def test_api_real_connection():
    client = FlumineBetfairClient(
        os.getenv('BETFAIR_USERNAME'),
        os.getenv('BETFAIR_PASSWORD'),
        os.getenv('BETFAIR_APP_KEY'),
        os.getenv('BETFAIR_CERT_PATH')
    )
    assert client.login() == True  # This will try to log in with actual credentials
    assert client.is_connected() == True  # This checks if the client can keep the session alive
