#include <stdio.h>
#include <string.h>
#include "storage.h"

static char db_file[256] = "users.db";

void set_db_file(const char *filename)
{
    strncpy(db_file, filename, sizeof(db_file) - 1);
    db_file[sizeof(db_file) - 1] = '\0';
}

int save_user(User user)
{
    FILE *file = fopen(db_file, "a");
    if (!file)
        return 0;

    fprintf(file, "%s %s\n", user.username, user.password);
    fclose(file);
    return 1;
}

int find_user(const char *username, User *result)
{
    FILE *file = fopen(db_file, "r");
    if (!file)
        return 0;

    User temp;
    while (fscanf(file, "%49s %49s", temp.username, temp.password) == 2)
    {
        if (strcmp(temp.username, username) == 0)
        {
            if (result)
                *result = temp;
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}