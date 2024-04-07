var API_BASE_URL = 'http://localhost:5000'; // Update with your backend server URL

function updateBotStatus(text, className) {
  const statusElement = document.getElementById('botStatus');
  if (statusElement) {
      statusElement.textContent = text;
      statusElement.classList.remove('bot-running', 'bot-stopped');
      statusElement.classList.add(className);
  }
}

function startBot() {
  fetch(API_BASE_URL + '/start', { method: 'POST' })
    .then(response => {
      if (response.ok) {
        console.log('Bot started successfully');
        updateBotStatus('Bot is running', 'bot-running');
      } else {
        console.error('Failed to start bot:', response.statusText);
        updateBotStatus('Bot is not running', 'bot-stopped');
      }
    })
    .catch(error => {
      console.error('Error starting bot:', error);
      updateBotStatus('Bot is not running', 'bot-stopped');
    });
}

function stopBot() {
  fetch(API_BASE_URL + '/stop', { method: 'POST' })
    .then(response => {
      if (response.ok) {
        console.log('Bot stopped successfully');
        updateBotStatus('Bot is not running', 'bot-stopped');
      } else {
        console.error('Failed to stop bot:', response.statusText);
        updateBotStatus('Bot is not running', 'bot-stopped');
      }
    })
    .catch(error => {
      console.error('Error stopping bot:', error);
      updateBotStatus('Bot is not running', 'bot-stopped');
    });
}

// The below function fetches bot status from the server
function fetchBotStatus() {
  fetch(API_BASE_URL + '/bot-status')
    .then(response => response.json())
    .then(data => {
      if (data.is_running) {
        updateBotStatus('Bot is running', 'bot-running');
      } else {
        updateBotStatus('Bot is not running', 'bot-stopped');
      }
    })
    .catch(error => {
      console.error('Error fetching bot status:', error);
    });
}

// Call fetchBotStatus when the page loads and after starting/stopping the bot
document.addEventListener('DOMContentLoaded', fetchBotStatus);

// Call fetchBotStatus after starting/stopping the bot to reflect the new status
// Consider using event listeners or a callback pattern if you want this to trigger only after certain user actions.
