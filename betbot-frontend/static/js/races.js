function fetchAndDisplayRaces() {
  const countrySelect = document.getElementById('countrySelect').value;
  const dateSelect = document.getElementById('dateSelect').value;
  const sportSelect = document.getElementById('sportSelect').value;
  const raceListElement = document.getElementById('raceList');
  const queryParameters = `countryCode=${countrySelect}&date=${dateSelect}&eventTypeId=${sportSelect}`;
  const url = `http://localhost:5000/api/races-for-date?${queryParameters}`;

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

      if (races && Array.isArray(races)) {
        // Sort races by start time in ascending order
        races.sort((a, b) => new Date(a.market_start_time) - new Date(b.market_start_time));

        races.forEach(race => {
          const raceElement = document.createElement('div');
          raceElement.className = 'race-item';

          // Generate the race item content based on the race data
          raceElement.innerHTML = `
            <h3><a href="race-details.html?raceId=${race.market_id}">${race.event_name}</a></h3>
            <p>Starts at: ${formatTime(race.market_start_time)}</p>
            <!-- Add more race details as needed -->
          `;

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

// Helper function to format the time
function formatTime(dateString) {
  const options = { hour: '2-digit', minute: '2-digit' };
  return new Date(dateString).toLocaleTimeString([], options);
}

document.addEventListener('DOMContentLoaded', () => {
  // Fetch and display races when any of the filter options are changed
  document.getElementById('countrySelect').addEventListener('change', fetchAndDisplayRaces);
  document.getElementById('dateSelect').addEventListener('change', fetchAndDisplayRaces);
  document.getElementById('sportSelect').addEventListener('change', fetchAndDisplayRaces);

  // Optionally, trigger a fetch when the page loads to display initial data
  fetchAndDisplayRaces();
});