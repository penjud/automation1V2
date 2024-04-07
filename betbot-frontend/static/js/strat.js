const API_BASE_URL = 'http://localhost:5000'; 

const navigationUrl = 'https://api-au.betfair.com/exchange/betting/rest/v1/en/navigation/';

async function fetchRaces(country, sport) {
  try {
    const eventTypeId = getEventTypeId(sport);
    const url = `${navigationUrl}${eventTypeId}/${country}`;

    console.log('Fetching races from URL:', url);

    const response = await fetch(url, {
      method: 'GET',
      headers: {
        'Accept': 'application/json',
        'X-Application': 'YOUR_APP_KEY',
        'X-Authentication': 'YourSessionToken'
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

function displayRaces(races) {
  const raceList = document.getElementById('raceList');
  raceList.innerHTML = '';

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

document.getElementById('country').addEventListener('change', updateRaces);
document.getElementById('sport').addEventListener('change', updateRaces);

function updateRaces() {
  const country = document.getElementById('country').value;
  const sport = document.getElementById('sport').value;
  fetchRaces(country, sport);
}

updateRaces();
