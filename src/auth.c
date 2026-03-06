#include <string.h>
#include "auth.h"
#include "storage.h"

int register_user(const char *username, const char *password)
{
    User existing;

    if (find_user(username, &existing))
    {
        return 0;
    }

    User user;
    strcpy(user.username, username);
    strcpy(user.password, password);

    return save_user(user);
}

int login_user(const char *username, const char *password)
{
    User user;

    if (!find_user(username, &user))
    {
        return 0;
    }

    if (strcmp(user.password, password) == 0)
    {
        return 1;
    }

    return 0;
}