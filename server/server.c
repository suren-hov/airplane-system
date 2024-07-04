#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "auth/auth.h"
#include "book_flights/book_flights.h"
#include "flights/flights.h"
#include "users/users.h"

#define PORT 9999
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

pthread_mutex_t lock;

void *handle_client(void *client_socket);
void process_request(char *request, char *response);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t tid;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket == -1) {
            perror("Accept failed");
            continue;
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (pthread_create(&tid, NULL, handle_client, &client_socket) != 0) {
            perror("Thread creation failed");
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received: %s\n", buffer);

        char response[BUFFER_SIZE];
        process_request(buffer, response);

        send(sock, response, strlen(response), 0);
    }

    close(sock);
    pthread_exit(NULL);
}

void process_request(char *request, char *response) {
    // Process request and generate appropriate response
    // ...
    strcpy(response, "Request processed");
}
