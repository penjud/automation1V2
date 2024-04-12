import pytest
from unittest.mock import patch, MagicMock
from flumine_bf_client import FlumineBetfairClient
import os

# Example of a Mocked Test
@patch('betfairlightweight.APIClient')
def test_api_login(mock_api_client):
    # Setting up the environment variables for the client
    os.environ['BETFAIR_USERNAME'] = 'username'
    os.environ['BETFAIR_PASSWORD'] = 'password'
    os.environ['BETFAIR_APP_KEY'] = 'app_key'
    os.environ['BETFAIR_CERT_PATH'] = '/path/to/certs'
    
    mock_api_client.return_value.login.return_value = 'session_token'
    client = FlumineBetfairClient('username', 'password', 'app_key', '/path/to/certs')
    assert client.login() == True
    assert client.session_token == 'session_token'