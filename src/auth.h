#ifndef AUTH_H
#define AUTH_H

typedef struct
{
    char username[51];
    char password[51];
} User;

int register_user(const char *username, const char *password);
int login_user(const char *username, const char *password);

#endif