#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "flights.h"

#define BUFFER_SIZE 1024

void cancel_flight(int client_socket) {
    char flight_id[BUFFER_SIZE], passenger_details[BUFFER_SIZE], data[BUFFER_SIZE];

    printf("Enter flight ID: ");
    scanf("%s", flight_id);
    printf("Enter passenger details: ");
    scanf("%s", passenger_details);

    sprintf(data, "%s %s", flight_id, passenger_details);
    send_request(client_socket, "cancel_flight", data);

    handle_response(client_socket);
}
