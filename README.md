# Project Components

## Core Components

| Component               | Description                                                                       |
|-------------------------|-----------------------------------------------------------------------------------|
| `.env`                  | Configures project settings and secrets securely.                                 |
| `betfair_client.py`     | Interfaces with the Betfair API for fetching and processing betting data.         |
| `bkstrat.py`            | Implements the core logic for betting strategies and decision-making.             |
| `certs`                 | Stores security certificates for authentication and secure communications.        |
| `favicon.ico`           | Represents the site's icon in the browser tab.                                    |
| `jupyter`               | Contains analytical or exploratory data analysis notebooks.                       |
| `main.py`               | The main entry point for the application, orchestrating various components.       |
| `node`                  | May contain Node.js or JavaScript files for web-related functionalities.         |
| `server.py`             | Manages server-side operations, possibly handling API requests and responses.     |
| `tests`                 | Includes test cases and scripts to ensure code reliability and functionality.     |

## Frontend Structure

| Component               | Description                                                                       |
|-------------------------|-----------------------------------------------------------------------------------|
| HTML                    | Markup files defining the structure of the web application's interface.           |
| CSS                     | Style sheets used to control the presentation, formatting, and layout.            |
| JavaScript              | Scripts providing interactive elements and integrating with backend APIs.         |
| Assets                  | Contains images, icons, and other media used in the frontend.                     |
| Framework-specific Files| If a specific frontend framework is used, related configuration and component files. |

---

# Usage
This bot will connect with teh betfair api and allow a user to see the sports for the day (currently Horses and greyhounds only.  We are developing a way to see the EV within a list of runners and highlight the best in the group based on the strategies set by the user and incorporating references to historical data to combine data (not yet developed) to point out the best betting option for the user.
Developers are looking at integrating AI to guide the decisions and bet placement.
