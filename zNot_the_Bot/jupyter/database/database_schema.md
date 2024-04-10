# Comprehensive Sports Betting Database Schema

## Core Entities

### Sports
- `sport_id` (Integer, Auto Increment, **Primary Key**)
- `name` (String) - Name of the sport, e.g., Soccer, Tennis, AFL, etc.

### Events
- `event_id` (Integer, Auto Increment, **Primary Key**)
- `sport_id` (Integer, **Foreign Key** to `Sports`)
- `name` (String) - Name of the match or tournament
- `start_time` (DateTime)
- `venue` (String, Nullable) - Specific for racing and certain sports events

### Markets
- `market_id` (Integer, Auto Increment, **Primary Key**)
- `event_id` (Integer, **Foreign Key** to `Events`)
- `market_name` (String)
- `market_type` (String)
- `market_time` (DateTime)
- `market_status` (String)
- `number_of_winners` (Integer, Nullable)
- `number_of_active_runners` (Integer, Nullable)
- `bet_delay` (Integer, Nullable)
- `bsp_reconciled` (Boolean, Nullable)
- `complete` (Boolean, Nullable)
- `in_play` (Boolean, Nullable)
- `cross_matching` (Boolean, Nullable)
- `runners_voidable` (Boolean, Nullable)
- `turn_in_play_enabled` (Boolean, Nullable)
- `version` (Integer, Nullable)

### Runners
- `runner_id` (Integer, Auto Increment, **Primary Key**)
- `market_id` (Integer, **Foreign Key** to `Markets`)
- `selection_id` (Integer, Nullable)
- `runner_name` (String)
- `handicap` (Double, Nullable)
- `status` (String)
- `sort_priority` (Integer, Nullable)
- `last_traded_price` (Double, Nullable)
- `total_matched` (Double, Nullable)
- `adjustment_factor` (Double, Nullable)
- `removal_date` (DateTime, Nullable)

## User and Account Management

### Users
- `user_id` (Integer, Auto Increment, **Primary Key**)
- `username` (String, Unique)
- `email` (String, Unique)
- `password_hash` (String) - Storing hash of the password for security
- `api_key` (String, Nullable) - Betfair API key or other integration
- `session_token` (String, Nullable) - For managing user sessions

### UserIPWhitelist
- `whitelist_id` (Integer, Auto Increment, **Primary Key**)
- `user_id` (Integer, **Foreign Key** to `Users`)
- `ip_address` (String) - Allowed IP address for the user

## Betting Data

### Bets
- `bet_id` (Integer, Auto Increment, **Primary Key**)
- `user_id` (Integer, **Foreign Key** to `Users`)
- `market_id` (Integer, **Foreign Key** to `Markets`)
- `runner_id` (Integer, **Foreign Key** to `Runners`)
- `stake` (Decimal)
- `price` (Decimal)
- `placed_at` (DateTime)
- `outcome` (String, Nullable)

## Historical and Dynamic Data Capture

### MarketChanges
- `change_id` (Integer, Auto Increment, **Primary Key**)
- `market_id` (Integer, **Foreign Key** to `Markets`)
- `published_time` (DateTime)
- `change_type` (String)

### PriceVolumeData
- `data_id` (Integer, Auto Increment, **Primary Key**)
- `runner_id` (Integer, **Foreign Key** to `Runners`, Nullable)
- `market_id` (Integer, **Foreign Key** to `Markets`, Nullable)
- `price` (Double)
- `volume` (Double)
- `time_recorded` (DateTime)

### HistoricalData
- `historical_id` (Integer, Auto Increment, **Primary Key**)
- `market_id` (Integer, **Foreign Key** to `Markets`)
- `event_id` (Integer, **Foreign Key** to `Events`)
- `data` (Text)
- `captured_at` (DateTime)

## Additional Data for In-Depth Analysis

### AdditionalData
- `additional_data_id` (Integer, Auto Increment, **Primary Key**)
- `event_id` (Integer, **Foreign Key** to `Events`)
- `data_type` (String)
- `value` (Text)

## Compliance and Usage Tracking

### BetfairAPIUsage
- `usage_id` (Integer, Auto Increment, **Primary Key**)
- `user_id` (Integer, **Foreign Key** to `Users`)
- `api_key` (String, Nullable) - The Betfair API key used for tracking
- `operation` (String) - Type of operation performed on the API
- `timestamp` (DateTime) - When the operation was executed

## Schema Notes and Best Practices

- **Security**: User passwords are stored as hashes to enhance security. IP whitelisting adds an additional layer of security for user accounts.
- **API Integration**: Storing API keys and tracking API usage aligns with Betfair’s compliance requirements and facilitates monitoring of API interactions.
- **Historical Data**: The schema is designed to support extensive historical data analysis for various sports, with separate tables for dynamic market changes and price-volume data, enabling detailed market analysis and strategy back-testing.
- **Extensibility**: The schema supports a wide range of sports and betting types, allowing for future expansion to include new sports, betting markets, and data types.
- **Market and Runner Details**: Detailed market and runner tables reflect the dynamic nature of betting markets, capturing real-time changes and historical performance.

This comprehensive schema provides a robust foundation for a sports betting database system, accommodating real-time betting data, historical analysis, user management, and API compliance. It’s designed to be adaptable for future enhancements and integrations with various sports data sources.
