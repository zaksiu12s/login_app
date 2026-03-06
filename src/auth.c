#include <string.h>
#include "auth.h"
#include "storage.h"

#define REG_SUCCESS 1
#define REG_TOO_SHORT_USERNAME 2
#define REG_TOO_LONG_USERNAME 3
#define REG_TOO_SHORT_PASSWORD 4
#define REG_TOO_LONG_PASSWORD 5
#define REG_USER_EXISTS 6

int register_user(const char *username, const char *password)
{
    User existing;
    size_t len_username = strlen(username);
    size_t len_password = strlen(password);

    if (len_username < 3)
        return REG_TOO_SHORT_USERNAME;
    if (len_username > 50)
        return REG_TOO_LONG_USERNAME;
    if (len_password < 8)
        return REG_TOO_SHORT_PASSWORD;
    if (len_password > 50)
        return REG_TOO_LONG_PASSWORD;
    if (find_user(username, &existing))
        return REG_USER_EXISTS;

    User user;
    strcpy(user.username, username);
    strcpy(user.password, password);

    return save_user(user) ? REG_SUCCESS : REG_USER_EXISTS;
}

int login_user(const char *username, const char *password)
{
    User user;
    if (!find_user(username, &user))
        return 0;
    if (strcmp(user.password, password) == 0)
        return 1;
    return 0;
}