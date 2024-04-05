// Update with the actual endpoint that checks the Betfair API connection
const API_STATUS_URL = '/api/check-connection'; 

function checkApiConnection() {
  fetch(API_STATUS_URL)
    .then(response => {
      if (!response.ok) {
        throw new Error('Network response was not ok');
      }
      return response.json();
    })
    .then(data => {
      updateApiStatus(data.connected);
    })
    .catch(error => {
      updateApiStatus(false);
      console.error('Error checking API connection:', error);
    });
}

function updateApiStatus(connected) {
  const statusElement = document.getElementById('apiStatus');
  if (connected) {
    statusElement.textContent = 'Betfair API connected';
    statusElement.style.color = 'green';
  } else {
    statusElement.textContent = 'Betfair API disconnected';
    statusElement.style.color = 'red';
  }
}

// Initial check
checkApiConnection();
