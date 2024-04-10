// ... (previous code remains the same)

function startBot() {
  fetch(`${API_BASE_URL}/start`, { method: 'POST' })
    .then(response => {
      if (response.ok) {
        console.log('Bot started successfully');
        updateStatusMessage('The bot is running', 'running');
      } else {
        console.error('Failed to start bot:', response.statusText);
        updateStatusMessage('Failed to start bot', 'not-running');
      }
    })
    .catch(error => {
      console.error('Error starting bot:', error);
      updateStatusMessage('Error starting bot', 'not-running');
    });
}

function stopBot() {
  fetch(`${API_BASE_URL}/stop`, { method: 'POST' })
    .then(response => {
      if (response.ok) {
        console.log('Bot stopped successfully');
        updateStatusMessage('The bot is not running', 'not-running');
      } else {
        console.error('Failed to stop bot:', response.statusText);
        updateStatusMessage('Failed to stop bot', 'not-running');
      }
    })
    .catch(error => {
      console.error('Error stopping bot:', error);
      updateStatusMessage('Error stopping bot', 'not-running');
    });
}

function updateStatusMessage(message, className) {
  const statusMessage = document.getElementById('status-message');
  statusMessage.textContent = message;
  statusMessage.className = className;
}