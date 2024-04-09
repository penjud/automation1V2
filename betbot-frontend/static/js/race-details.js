document.addEventListener('DOMContentLoaded', () => {
  const urlParams = new URLSearchParams(window.location.search);
  const raceId = urlParams.get('raceId');

  if (raceId) {
    fetchRaceDetails(raceId);
  } else {
    console.error('Race ID not provided.');
  }
});

function fetchRaceDetails(raceId) {
  const url = `http://localhost:5000/api/race-details?raceId=${raceId}`;

  fetch(url)
    .then(response => {
      if (!response.ok) {
        throw new Error(`HTTP error! status: ${response.status}`);
      }
      return response.json();
    })
    .then(raceDetails => {
      displayRaceDetails(raceDetails);
    })
    .catch(error => {
      console.error('Error fetching race details:', error);
    });
}

function displayRaceDetails(raceDetails) {
  const raceDetailsElement = document.getElementById('raceDetails');
  raceDetailsElement.innerHTML = ''; // Clear previous content

  // Display race details
  const raceNameElement = document.createElement('h2');
  raceNameElement.textContent = raceDetails.event_name;
  raceDetailsElement.appendChild(raceNameElement);

  // Display runner details
  const runnersElement = document.createElement('ul');
  raceDetails.runners.forEach(runner => {
    const runnerElement = document.createElement('li');
    runnerElement.innerHTML = `
      <strong>${runner.runner_name}</strong>
      <ul>
        <li>Barrier: ${runner.metadata.STALL_DRAW}</li>
        <li>Jockey: ${runner.metadata.JOCKEY_NAME}</li>
        <li>Trainer: ${runner.metadata.TRAINER_NAME}</li>
        <!-- Add more runner details as needed -->
      </ul>
    `;
    runnersElement.appendChild(runnerElement);
  });
  raceDetailsElement.appendChild(runnersElement);
}