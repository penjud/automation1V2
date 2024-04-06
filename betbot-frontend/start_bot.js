var API_BASE_URL = 'http://localhost:5000'; // Update with your backend server URL

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
  const statusElement = document.getElementById('botStatus');
  if (statusElement) {
      statusElement.textContent = 'Bot is running';
      statusElement.style.color = 'green';
  }
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
  const statusElement = document.getElementById('botStatus');
  if (statusElement) {
      statusElement.textContent = 'Bot is not running';
      statusElement.style.color = 'red';
  }
}

// start_bot.js
function updateBotStatus() {
  fetch(API_BASE_URL + '/bot-status')
    .then(response => response.json())
    .then(data => {
      const statusElement = document.getElementById('botStatus');
      if (data.is_running) {
        statusElement.textContent = 'Bot is running';
        statusElement.classList.remove('bot-stopped');
        statusElement.classList.add('bot-running');
      } else {
        statusElement.textContent = 'Bot is not running';
        statusElement.classList.remove('bot-running');
        statusElement.classList.add('bot-stopped');
      }
    })
    .catch(error => {
      console.error('Error updating bot status:', error);
    });
}

// Call updateBotStatus when the page loads and after starting/stopping the bot
document.addEventListener('DOMContentLoaded', updateBotStatus);
