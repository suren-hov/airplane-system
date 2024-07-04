#include <stdio.h>
#include <string.h>
#include "auth/auth.h"
#include "book_flights/book_flights.h"
#include "flights/flights.h"
#include "users/users.h"

void process_request(char *request, char *response) {
    char command[20], arg1[50], arg2[100];
    sscanf(request, "%s %s %s", command, arg1, arg2);

    if (strcmp(command, "login") == 0) {
        if (login(arg1, arg2)) {
            strcpy(response, "Login successful");
        } else {
            strcpy(response, "Login failed");
        }
    } else if (strcmp(command, "register") == 0) {
        if (register_user(arg1, arg2)) {
            strcpy(response, "Registration successful");
        } else {
            strcpy(response, "Registration failed");
        }
    } else if (strcmp(command, "create_flight") == 0) {
        create_flight(arg1, arg2);
        strcpy(response, "Flight created");
    } else if (strcmp(command, "update_flight") == 0) {
        update_flight(arg1, arg2);
        strcpy(response, "Flight updated");
    } else if (strcmp(command, "delete_flight") == 0) {
        delete_flight(arg1);
        strcpy(response, "Flight deleted");
    } else if (strcmp(command, "get_flights") == 0) {
        get_flights(response);
    } else if (strcmp(command, "book_flight") == 0) {
        book_flight(arg1, arg2);
        strcpy(response, "Flight booked");
    } else if (strcmp(command, "cancel_flight") == 0) {
        cancel_flight(arg1, arg2);
        strcpy(response, "Flight cancelled");
    } else if (strcmp(command, "get_booked_flights") == 0) {
        get_booked_flights(response);
    } else if (strcmp(command, "get_user_info") == 0) {
        get_user_info(arg1, response);
    } else if (strcmp(command, "update_user_info") == 0) {
        update_user_info(arg1, arg2);
        strcpy(response, "User info updated");
    } else if (strcmp(command, "delete_user") == 0) {
        delete_user(arg1);
        strcpy(response, "User deleted");
    } else {
        strcpy(response, "Unknown command");
    }
}
