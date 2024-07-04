#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "auth/auth.h"
#include "flights/flights.h"
#include "client_utils.h"

#define PORT 9999

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char action[20], data[BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Book Flight\n");
        printf("4. Cancel Flight\n");
        printf("5. View Flights\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%s", action);

        if (strcmp(action, "1") == 0) {
            login(client_socket);
        } else if (strcmp(action, "2") == 0) {
            register_user(client_socket);
        } else if (strcmp(action, "3") == 0) {
            book_flight(client_socket);
        } else if (strcmp(action, "4") == 0) {
            cancel_flight(client_socket);
        } else if (strcmp(action, "5") == 0) {
            view_flights(client_socket);
        } else if (strcmp(action, "6") == 0) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    close(client_socket);
    return 0;
}

void send_request(int client_socket, char *action, char *data) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s %s", action, data);
    send(client_socket, buffer, strlen(buffer), 0);
}

void handle_response(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);
}
