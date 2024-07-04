# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -pthread

# Directories
SERVER_DIR = server
CLIENT_DIR = client
SERVER_AUTH_DIR = $(SERVER_DIR)/auth
SERVER_BOOK_FLIGHTS_DIR = $(SERVER_DIR)/book_flights
SERVER_FLIGHTS_DIR = $(SERVER_DIR)/flights
SERVER_USERS_DIR = $(SERVER_DIR)/users
CLIENT_AUTH_DIR = $(CLIENT_DIR)/auth
CLIENT_FLIGHTS_DIR = $(CLIENT_DIR)/flights

# Server sources and objects
SERVER_SRCS = $(SERVER_DIR)/server.c \
              $(SERVER_AUTH_DIR)/login.c \
              $(SERVER_AUTH_DIR)/register.c \
              $(SERVER_BOOK_FLIGHTS_DIR)/book_flight.c \
              $(SERVER_BOOK_FLIGHTS_DIR)/booked_flights.c \
              $(SERVER_BOOK_FLIGHTS_DIR)/cancel_flight.c \
              $(SERVER_FLIGHTS_DIR)/create_flight.c \
              $(SERVER_FLIGHTS_DIR)/delete_flight.c \
              $(SERVER_FLIGHTS_DIR)/get_flights.c \
              $(SERVER_FLIGHTS_DIR)/update_flight.c \
              $(SERVER_USERS_DIR)/delete_user.c \
              $(SERVER_USERS_DIR)/get_user_info.c \
              $(SERVER_USERS_DIR)/update_user_info.c \
              $(SERVER_DIR)/menu.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# Client sources and objects
CLIENT_SRCS = $(CLIENT_DIR)/client.c \
              $(CLIENT_AUTH_DIR)/login.c \
              $(CLIENT_AUTH_DIR)/register.c \
              $(CLIENT_FLIGHTS_DIR)/book_flight.c \
              $(CLIENT_FLIGHTS_DIR)/cancel_flight.c \
              $(CLIENT_FLIGHTS_DIR)/view_flights.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

# Targets
TARGET_SERVER = server_executable
TARGET_CLIENT = client_executable

# Build the server
$(TARGET_SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(TARGET_SERVER) $(SERVER_OBJS)

# Build the client
$(TARGET_CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT) $(CLIENT_OBJS)

# Compile server object files
$(SERVER_DIR)/%.o: $(SERVER_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_AUTH_DIR)/%.o: $(SERVER_AUTH_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_BOOK_FLIGHTS_DIR)/%.o: $(SERVER_BOOK_FLIGHTS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_FLIGHTS_DIR)/%.o: $(SERVER_FLIGHTS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_USERS_DIR)/%.o: $(SERVER_USERS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile client object files
$(CLIENT_DIR)/%.o: $(CLIENT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_AUTH_DIR)/%.o: $(CLIENT_AUTH_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_FLIGHTS_DIR)/%.o: $(CLIENT_FLIGHTS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(TARGET_SERVER) $(TARGET_CLIENT)

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET_SERVER) $(TARGET_CLIENT)
