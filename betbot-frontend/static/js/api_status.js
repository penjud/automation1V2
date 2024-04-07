// api_status.js
function checkApiStatus() {
  fetch(API_BASE_URL + '/api/check-connection')
    .then(response => response.json())
    .then(data => {
      const apiStatusElement = document.getElementById('apiStatus');
      if (data.connected) {
        apiStatusElement.textContent = 'Betfair API is connected';
        apiStatusElement.classList.remove('api-disconnected');
        apiStatusElement.classList.add('api-connected');
      } else {
        apiStatusElement.textContent = 'Betfair API is disconnected';
        apiStatusElement.classList.remove('api-connected');
        apiStatusElement.classList.add('api-disconnected');
      }
    })
    .catch(error => {
      console.error('Error checking API status:', error);
    });
}

// Call checkApiStatus when the page loads and periodically
document.addEventListener('DOMContentLoaded', checkApiStatus);
setInterval(checkApiStatus, 10000); // Check every 10 seconds
