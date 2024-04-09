const API_BASE_URL = 'http://localhost:5000'; // Update with your backend server URL

function fetchRaces() {
    const countryCode = document.getElementById('countrySelect').value;
    const eventTypeId = document.getElementById('sportSelect').value;
    const selectedDate = document.getElementById('dateSelect').value;
    const marketCount = 10;
  
    fetch(`${API_BASE_URL}/api/formatted-races?countryCode=${countryCode}&eventTypeId=${eventTypeId}&marketCount=${marketCount}&date=${selectedDate}`)
      .then(response => response.json())
      .then(data => {
        displayRaces(data);
      })
      .catch(error => {
        console.error('Error fetching races:', error);
        displayError('Failed to fetch race information. Please try again later.');
      });
  }

  function displayRaces(races) {
    const raceList = document.getElementById('raceList');
    raceList.innerHTML = ''; // Clear the existing race list
  
    races.forEach(race => {
      const raceItem = document.createElement('div');
      raceItem.classList.add('race-item');
      raceItem.innerHTML = `
        <h3>${race.event_name}</h3>
        <p>Start Time: ${race.market_start_time}</p>
        <p>Market Count: ${race.market_count}</p>
      `;
      raceList.appendChild(raceItem);
    });
  }
  function displayError(message) {
    const raceList = document.getElementById('raceList');
    raceList.innerHTML = `<p class="error">${message}</p>`;
  }
  document.getElementById('countrySelect').addEventListener('change', fetchRaces);
  document.getElementById('dateSelect').addEventListener('change', fetchRaces);
  document.getElementById('sportSelect').addEventListener('change', fetchRaces);
  
  // Call the fetchRaces function when the page loads
  document.addEventListener('DOMContentLoaded', fetchRaces);