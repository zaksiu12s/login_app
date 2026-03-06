#include <stdio.h>
#include <string.h>
#include "auth.h"

#define MAX_USERNAME 51
#define MAX_PASSWORD 51

void clear_input()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void menu()
{
    printf("\n1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
}

void read_line(char *buffer, int max_len)
{
    if (fgets(buffer, max_len, stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
        else
        {
            clear_input();
        }
    }
}

int main()
{
    int choice;
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    while (1)
    {
        menu();
        printf("Choice: ");

        char choice_buffer[10];
        read_line(choice_buffer, sizeof(choice_buffer));
        choice = atoi(choice_buffer);

        if (choice < 1 || choice > 3)
        {
            printf("Invalid option. Choose 1, 2, or 3.\n");
            continue;
        }

        if (choice == 1)
        {
            printf("Username (3-50 chars): ");
            read_line(username, sizeof(username));

            int len_username = strlen(username);
            if (len_username < 3)
            {
                printf("Username too short. Must be at least 3 characters.\n");
                continue;
            }

            printf("Password (8-50 chars): ");
            read_line(password, sizeof(password));

            int len_password = strlen(password);
            if (len_password < 8)
            {
                printf("Password too short. Must be at least 8 characters.\n");
                continue;
            }

            if (register_user(username, password))
            {
                printf("Registration successful\n");
            }
            else
            {
                printf("User already exists\n");
            }
        }
        else if (choice == 2)
        {
            printf("Username: ");
            read_line(username, sizeof(username));

            printf("Password: ");
            read_line(password, sizeof(password));

            if (login_user(username, password))
            {
                printf("Login successful\n");
            }
            else
            {
                printf("Invalid credentials\n");
            }
        }
        else if (choice == 3)
        {
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}