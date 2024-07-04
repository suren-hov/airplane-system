#ifndef FLIGHTS_H
#define FLIGHTS_H

void create_flight(const char *flight_id, const char *details);
void update_flight(const char *flight_id, const char *new_details);
void delete_flight(const char *flight_id);
void get_flights(char *response);

#endif
