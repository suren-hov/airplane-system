#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "auth.h"

#define BUFFER_SIZE 1024

void login(int client_socket) {
    char username[BUFFER_SIZE], password[BUFFER_SIZE], data[BUFFER_SIZE];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sprintf(data, "%s %s", username, password);
    send_request(client_socket, "login", data);

    handle_response(client_socket);
}
