document.getElementById('profileForm').addEventListener('submit', function(e) {
    e.preventDefault();
    
    const apiKey = document.getElementById('apiKey').value;
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;
    const certFile = document.getElementById('certFile').files[0];
    const keyFile = document.getElementById('keyFile').files[0];
    
    const formData = new FormData();
    formData.append('apiKey', apiKey);
    formData.append('username', username);
    formData.append('password', password);
    formData.append('certFile', certFile);
    formData.append('keyFile', keyFile);
    
    fetch('/api/profile', {
      method: 'POST',
      body: formData
    })
    .then(response => response.json())
    .then(data => {
      if (data.success) {
        // Display success message
        alert('Profile updated successfully.');
      } else {
        // Display error message
        alert('Failed to update profile. Please try again.');
      }
    })
    .catch(error => {
      console.error('Error:', error);
    });
  });