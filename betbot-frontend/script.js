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
        statusElement.style.color = 'green'; // Change the text color to green
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
      statusElement.style.color = 'red'; // Change the text color to red
    }
}

function updateBotStatus(message, statusClass) {
  var botStatusElement = document.getElementById('botStatus');
  botStatusElement.textContent = message;
  botStatusElement.className = 'bot-status ' + statusClass;
}
/// Function to fetch races based on selected country and sport
function fetchRaces(country, sport) {
  const eventTypeId = getEventTypeId(sport);
  const apiUrl = `https://api-au.betfair.com/exchange/betting/rest/v1/en/navigation/${eventTypeId}/${country}`;
  fetch(apiUrl, {
    headers: {
      'Accept': 'application/json',
      'X-Application': 'YourAppName',
      'X-Authentication': 'YourSessionToken'
    }
  })
    .then(response => response.json())
    .then(data => {
      const races = data.children[0].children;
      const raceList = document.getElementById('raceList');
      raceList.innerHTML = ''; // Clear the existing race list

      races.forEach(race => {
        const raceItem = document.createElement('div');
        raceItem.classList.add('race-item');

        const checkbox = document.createElement('input');
        checkbox.type = 'checkbox';
        checkbox.id = `race-${race.id}`;
        checkbox.name = `race-${race.id}`;

        const label = document.createElement('label');
        label.htmlFor = `race-${race.id}`;
        label.textContent = race.name;

        raceItem.appendChild(checkbox);
        raceItem.appendChild(label);
        raceList.appendChild(raceItem);
      });
    })
    .catch(error => {
      console.error('Error fetching races:', error);
    });
}

// Function to get the event type ID based on the selected sport
function getEventTypeId(sport) {
  switch (sport) {
    case 'horseracing':
      return '7';
    case 'greyhounds':
      return '4339';
    default:
      return '';
  }
}

// Event listener for country and sport selection change
document.getElementById('country').addEventListener('change', updateRaces);
document.getElementById('sport').addEventListener('change', updateRaces);

function updateRaces() {
  const country = document.getElementById('country').value;
  const sport = document.getElementById('sport').value;
  fetchRaces(country, sport);
}

// Initial fetch of races
updateRaces();

// Betfair API endpoint for navigation data
const navigationUrl = 'https://api-au.betfair.com/exchange/betting/rest/v1/en/navigation/';

// Function to fetch races based on selected country and sport
async function fetchRaces(country, sport) {
  try {
    const eventTypeId = getEventTypeId(sport);
    const url = `${navigationUrl}${eventTypeId}/${country}`;

    console.log('Fetching races from URL:', url);

    const response = await fetch(url, {
      method: 'GET',
      headers: {
        'Accept': 'application/json',
        'X-Application': 'YOUR_APP_KEY'
      },
      mode: 'cors'
    });

    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }

    const data = await response.json();
    console.log('Fetched race data:', data);

    const races = data.children[0].children;
    console.log('Extracted races:', races);

    displayRaces(races);
  } catch (error) {
    console.error('Error fetching races:', error);
  }
}

// Function to get the event type ID based on the selected sport
function getEventTypeId(sport) {
  switch (sport) {
    case 'horse-racing':
      return '7';
    case 'greyhound-racing':
      return '4339';
    default:
      return '';
  }
}

// Function to display the list of races
function displayRaces(races) {
  const raceList = document.getElementById('raceList');
  raceList.innerHTML = ''; // Clear the existing race list

  console.log('Displaying races:', races);

  races.forEach(race => {
    const raceItem = document.createElement('div');
    raceItem.classList.add('race-item');

    const checkbox = document.createElement('input');
    checkbox.type = 'checkbox';
    checkbox.id = `race-${race.id}`;
    checkbox.name = `race-${race.id}`;

    const label = document.createElement('label');
    label.htmlFor = `race-${race.id}`;
    label.textContent = race.name;

    raceItem.appendChild(checkbox);
    raceItem.appendChild(label);
    raceList.appendChild(raceItem);
  });
}

// Event listener for country and sport selection change
document.getElementById('country').addEventListener('change', updateRaces);
document.getElementById('sport').addEventListener('change', updateRaces);

// Function to update the races based on the selected country and sport
function updateRaces() {
  const country = document.getElementById('country').value;
  const sport = document.getElementById('sport').value;

  console.log('Selected country:', country);
  console.log('Selected sport:', sport);

  fetchRaces(country, sport);
}

// Initial fetch of races
updateRaces();