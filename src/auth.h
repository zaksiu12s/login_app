#ifndef AUTH_H
#define AUTH_H

#define USERNAME_MAX 51
#define PASSWORD_MAX 51

typedef struct
{
    char username[USERNAME_MAX];
    char password[PASSWORD_MAX];
} User;

int register_user(const char *username, const char *password);
int login_user(const char *username, const char *password);

#endif