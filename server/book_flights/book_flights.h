#ifndef BOOK_FLIGHTS_H
#define BOOK_FLIGHTS_H

void book_flight(const char *flight_id, const char *passenger_details);
void cancel_flight(const char *flight_id, const char *passenger_details);
void get_booked_flights(char *response);

#endif
