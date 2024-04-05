const API_BASE_URL = 'http://localhost:5000'; // Update with your backend server URL

function fetchAccountFunds() {
  fetch(API_BASE_URL + '/api/account-funds')
    .then(response => response.json())
    .then(data => {
      if (data.availableFunds) {
        displayAccountFunds(data.availableFunds);
      } else {
        console.error('Failed to retrieve account funds');
      }
    })
    .catch(error => {
      console.error('Error fetching account funds:', error);
    });
}

function displayAccountFunds(funds) {
  const accountFundsElement = document.getElementById('accountFunds');
  accountFundsElement.textContent = `Available Funds: ${funds}`;
}

// Call the fetchAccountFunds function when the page loads
document.addEventListener('DOMContentLoaded', fetchAccountFunds);
