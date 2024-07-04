#include <string.h>
#include "auth.h"

int login(const char *username, const char *password) {
    // Placeholder authentication logic
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
        return 1;
    }
    return 0;
}
