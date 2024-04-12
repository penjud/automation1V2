// login.js

document.getElementById('loginForm').addEventListener('submit', function(e) {
  e.preventDefault();
   
  const username = document.getElementById('username').value;
  const password = document.getElementById('password').value;
   
  // Modify the URL to include the full path to your Flask server
  fetch('http://localhost:5000/api/login', {
     method: 'POST',
     headers: {
       'Content-Type': 'application/json'
     },
     body: JSON.stringify({ username, password })
  })
  .then(response => {
     if (!response.ok) {
       throw new Error('Network response was not ok');
     }
     return response.json();
  })
  .then(data => {
     if (data.success) {
       // Redirect to profile page or bot interface
       window.location.href = '/profile.html';
     } else {
       // Display error message
       document.getElementById('message').textContent = data.message;
     }
  })
  .catch(error => {
     console.error('Error:', error);
     document.getElementById('message').textContent = 'An error occurred during login.';
  });
 });
 