#ifndef CLIENT_UTILS_H
#define CLIENT_UTILS_H

#define BUFFER_SIZE 1024

void send_request(int client_socket, char *action, char *data);
void handle_response(int client_socket);

#endif // CLIENT_UTILS_H
