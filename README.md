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
  - Authentication and admin functionalities.

## Example Scenario

1. **Client X** wants to book a flight from City A to City B on a specific date.
2. **Client Y** wants to check flight availability for a particular route.
3. **Client Z** wants to view passenger details for a booked flight.

The server manages these requests concurrently, updates flight availability, stores passenger information, and responds to each client appropriately.

## Installation

### Prerequisites

- C Compiler (e.g., gcc)

### Clone the Repository

```bash
git clone https://github.com/yourusername/airplane-management-system.git
cd airplane-management-system

## Project Structure

.
├── server
│   ├── server.c
│   ├── auth
│   │   ├── login.c
│   │   ├── register.c
│   │   ├── auth.h
│   ├── book_flights
│   │   ├── book_flight.c
│   │   ├── booked_flights.c
│   │   ├── cancel_flight.c
│   │   ├── book_flights.h
│   ├── flights
│   │   ├── create_flight.c
│   │   ├── delete_flight.c
│   │   ├── get_flights.c
│   │   ├── update_flight.c
│   │   ├── flights.h
│   ├── users
│   │   ├── delete_user.c
│   │   ├── get_user_info.c
│   │   ├── update_user_info.c
│   │   ├── users.h
│   ├── menu.c
├── client
│   ├── client.c
│   ├── auth
│   │   ├── login.c
│   │   ├── register.c
│   │   ├── auth.h
│   ├── flights
│   │   ├── book_flight.c
│   │   ├── cancel_flight.c
│   │   ├── view_flights.c
│   │   ├── flights.h
└── README.md
