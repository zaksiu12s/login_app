#include <stdio.h>
#include <string.h>
#include "storage.h"

#define DB_FILE "users.db"

int save_user(User user)
{
    FILE *file = fopen(DB_FILE, "a");
    if (!file)
        return 0;

    fprintf(file, "%s %s\n", user.username, user.password);
    fclose(file);
    return 1;
}

int find_user(const char *username, User *result)
{
    FILE *file = fopen(DB_FILE, "r");
    if (!file)
        return 0;

    User temp;

    while (fscanf(file, "%49s %49s", temp.username, temp.password) == 2)
    {
        if (strcmp(temp.username, username) == 0)
        {
            *result = temp;
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}