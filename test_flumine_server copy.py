import pytest
from unittest.mock import Mock, patch
from flumine_bf_client import get_betfair_client, FlumineBetfairClient
import logging

# Test the initialization and connection
@patch('flumine_bf_client.betfairlightweight.APIClient')
def test_client_initialization(mock_api_client):
    mock_api_client.return_value.login.return_value = 'session_token'
    client = get_betfair_client()
    assert client is not None
    assert client.session_token == 'session_token'

@patch('flumine_bf_client.betfairlightweight.APIClient')
def test_login_failure_logs_error(mock_api_client, caplog):
  mock_api_client.return_value.login.side_effect = Exception("Login failed")
  with caplog.at_level(logging.ERROR):
    client = get_betfair_client()
    assert "Failed to initialize Betfair client: Login failed" in caplog.text
    assert client is None
    assert client is None