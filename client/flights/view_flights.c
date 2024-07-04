#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "flights.h"

#define BUFFER_SIZE 1024

void view_flights(int client_socket) {
    char data[BUFFER_SIZE] = "";

    send_request(client_socket, "view_flights", data);

    handle_response(client_socket);
}
