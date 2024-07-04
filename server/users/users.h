#ifndef USERS_H
#define USERS_H

void get_user_info(const char *username, char *response);
void update_user_info(const char *username, const char *new_info);
void delete_user(const char *username);

#endif
