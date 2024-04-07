function fetchAndDisplayRaces() {
  const countrySelect = document.getElementById('countrySelect').value;
  const dateSelect = document.getElementById('dateSelect').value;
  const sportSelect = document.getElementById('sportSelect').value;
  const raceListElement = document.getElementById('raceList');
  const queryParameters = `countryCode=${countrySelect}&date=${dateSelect}&eventTypeId=${sportSelect}`;
  const url = `http://localhost:5000/api/races-for-date?${queryParameters}`;  // Ensure the URL is correct
        console.log(queryParameters);

  fetch(url)
    .then(response => {
      if (!response.ok) {
        throw new Error(`HTTP error! status: ${response.status}`);
      }
      return response.json();
    })
    .then(races => {
      raceListElement.innerHTML = ''; // Clear previous content

      if (races && Array.isArray(races)) {  // Check if data exists and is an array
        races.forEach(race => {
          const raceElement = document.createElement('div');
          raceElement.className = 'race-item';
          raceElement.innerHTML = `<h3>${race.event_name}</h3><p>Starts at: ${race.market_start_time}</p>`;
          raceListElement.appendChild(raceElement);
        });
      } else {
        raceListElement.innerHTML = '<p>No races found or error fetching races.</p>';
      }
    })
    .catch(error => {
      console.error('Error fetching races:', error);
      raceListElement.innerHTML = `<p>Error fetching race data: ${error.message}</p>`;
    });
}

document.addEventListener('DOMContentLoaded', () => {
  // Fetch and display races when any of the filter options are changed
  document.getElementById('countrySelect').addEventListener('change', fetchAndDisplayRaces);
  document.getElementById('dateSelect').addEventListener('change', fetchAndDisplayRaces);
  document.getElementById('sportSelect').addEventListener('change', fetchAndDisplayRaces);

  // Optionally, trigger a fetch when the page loads to display initial data
  fetchAndDisplayRaces();
});
