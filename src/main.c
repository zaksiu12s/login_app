#include <stdio.h>
#include <string.h>
#include "auth.h"

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

int main()
{
    int choice;
    char username[USERNAME_MAX];
    char password[PASSWORD_MAX];

    while (1)
    {
        menu();
        printf("Choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clear_input();
            continue;
        }

        if (choice < 1 || choice > 3)
        {
            printf("Invalid option. Choose 1, 2, or 3.\n");
            continue;
        }

        if (choice == 1)
        {
            printf("Username (3-50 chars): ");
            scanf("%50s", username);

            int len_username = strlen(username);
            if (len_username < 3)
            {
                printf("Username too short. Must be at least 3 characters.\n");
                continue;
            }
            if (len_username > 50)
            {
                printf("Username too long. Max 50 characters.\n");
                continue;
            }

            printf("Password (8-50 chars): ");
            scanf("%50s", password);

            int len_password = strlen(password);
            if (len_password < 8)
            {
                printf("Password too short. Must be at least 8 characters.\n");
                continue;
            }
            if (len_password > 50)
            {
                printf("Password too long. Max 50 characters.\n");
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
            scanf("%50s", username);

            printf("Password: ");
            scanf("%50s", password);

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