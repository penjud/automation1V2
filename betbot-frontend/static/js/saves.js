document.addEventListener('DOMContentLoaded', function() {
  const saveStrategyBtn = document.getElementById('saveStrategy');
  const loadStrategyBtn = document.getElementById('loadStrategy');
  const deleteStrategyBtn = document.getElementById('deleteStrategy');
  const strategyNameInput = document.getElementById('strategyNameInput');
  const savedStrategiesSelect = document.getElementById('savedStrategies');


  saveStrategyBtn.addEventListener('click', function() {
    const strategyName = strategyNameInput.value;
    const strategySettings = {}; // Ensure this is correctly populated with the strategy settings
    const dataToSend = { strategyName, strategySettings };
    console.log(JSON.stringify(dataToSend)); // Log the JSON data
    fetch('/api/save-strategy-to-file', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(dataToSend),
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        return response.json();
    })
    .then(data => console.log(data))
    .catch((error) => console.error('Error:', error));
});

  loadStrategyBtn.addEventListener('click', function() {
      const strategyName = savedStrategiesSelect.value;
      fetch(`/api/load-strategy-from-file?strategyName=${strategyName}`)
      .then(response => response.json())
      .then(data => {
          // Load the strategy settings into your UI
          console.log(data);
      })
      .catch((error) => console.error('Error:', error));
  });

  deleteStrategyBtn.addEventListener('click', function() {
      const strategyName = savedStrategiesSelect.value;
      fetch(`/api/delete-strategy-file?strategyName=${strategyName}`, {
          method: 'DELETE',
      })
      .then(response => response.json())
      .then(data => console.log(data))
      .catch((error) => console.error('Error:', error));
  });
});