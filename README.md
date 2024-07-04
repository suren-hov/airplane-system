# Airplane Management System

## Overview

The Airplane Management System is a client-server application designed to manage airplane operations such as flight booking, flight availability, and passenger information. The server handles all the operations, while multiple clients can connect to the server to perform various tasks.

## Features

- **Server**:
  - TCP/IP server that listens for incoming client connections.
  - Multi-threading to handle multiple clients concurrently.
  - Functions to add, modify, and delete flight information.
  - Functions to book flights, check flight availability, and cancel bookings.
  - Manage passenger information such as name, contact details, and flight preferences.
  - Thread safety using synchronization mechanisms.

- **Client**:
  - Interface to connect to the server.
  - Options to book flights, check availability, view passenger details, etc.
  - Handles user input for various operations.
  - Displays appropriate messages and responses from the server.

- **Additional Features (Optional)**:
  - Ticketing and boarding passes.
  - Admin panel to manage flight schedules and ticket prices.
  - Secure admin access with authentication.

## Example Scenario

1. **Client X** wants to book a flight from City A to City B on a specific date.
2. **Client Y** wants to check flight availability for a particular route.
3. **Client Z** wants to view passenger details for a booked flight.

The server manages these requests concurrently, updates flight availability, stores passenger information, and responds to each client appropriately.

## Installation

### Prerequisites

- Python 3.x

### Clone the Repository

```bash
git clone https://github.com/yourusername/airplane-management-system.git
cd airplane-management-system
