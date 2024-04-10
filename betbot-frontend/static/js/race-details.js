document.addEventListener('DOMContentLoaded', () => {
  const urlParams = new URLSearchParams(window.location.search);
  const raceId = urlParams.get('raceId');

  if (!raceId) {
      document.getElementById('raceDetails').innerHTML = '<p>No race ID provided.</p>';
      return;
  }

  fetch(`http://localhost:5000/api/race-details?raceId=${raceId}`)
      .then(response => {
          if (!response.ok) {
              throw new Error(`HTTP error! status: ${response.status}`);
          }
          return response.json();
      })
      .then(raceDetails => {
          // Assuming raceDetails is an object with the race's details
          document.getElementById('raceDetails').innerHTML = `
              <h2>${raceDetails.event_name}</h2>
              <p>Starts at: ${formatTime(raceDetails.market_start_time)}</p>
              <!-- Display other race details here -->
          `;
      })
      .catch(error => {
          console.error('Error fetching race details:', error);
          document.getElementById('raceDetails').innerHTML = `<p>Error fetching race details: ${error.message}</p>`;
      });
});

// Helper function to format the time
function formatTime(dateString) {
  const options = { hour: '2-digit', minute: '2-digit', hour12: false };
  return new Date(dateString).toLocaleTimeString([], options);
}
