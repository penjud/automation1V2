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

function updateBotStatus(message, statusClass) {
  var botStatusElement = document.getElementById('botStatus');
  botStatusElement.textContent = message;
  botStatusElement.className = 'bot-status ' + statusClass;
}
