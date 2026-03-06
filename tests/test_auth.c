#include <assert.h>
#include <stdio.h>
#include "../src/auth.h"
#include "../src/storage.h"

#define TEST_DB "test_users.db"

void clear_test_db()
{
    FILE *file = fopen(TEST_DB, "w");
    if (file)
        fclose(file);
}

void test_registration_success()
{
    int result = register_user("testuser", "password123");
    printf("Test: Registration success -> ");
    assert(result == 1);
    printf("PASSED\n");
}

void test_registration_short_username()
{
    int result = register_user("ab", "password123");
    printf("Test: Username too short -> ");
    assert(result == 2);
    printf("PASSED\n");
}

void test_registration_long_username()
{
    char long_username[52] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    int result = register_user(long_username, "password123");
    printf("Test: Username too long -> ");
    assert(result == 3);
    printf("PASSED\n");
}

void test_registration_short_password()
{
    int result = register_user("validuser", "short");
    printf("Test: Password too short -> ");
    assert(result == 4);
    printf("PASSED\n");
}

void test_registration_long_password()
{
    char long_password[52] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    int result = register_user("validuser2", long_password);
    printf("Test: Password too long -> ");
    assert(result == 5);
    printf("PASSED\n");
}

void test_registration_existing_user()
{
    register_user("existinguser", "password123");
    int result = register_user("existinguser", "password123");
    printf("Test: Registration of existing user -> ");
    assert(result == 6);
    printf("PASSED\n");
}

void test_login_success()
{
    register_user("loginuser", "password123");
    int result = login_user("loginuser", "password123");
    printf("Test: Login success -> ");
    assert(result == 1);
    printf("PASSED\n");
}

void test_login_fail()
{
    int result = login_user("nosuchuser", "password123");
    printf("Test: Login fail (nonexistent user) -> ");
    assert(result == 0);
    printf("PASSED\n");
}

int main()
{
    set_db_file(TEST_DB);
    clear_test_db();

    printf("Running tests...\n\n");

    test_registration_success();
    test_registration_short_username();
    test_registration_long_username();
    test_registration_short_password();
    test_registration_long_password();
    test_registration_existing_user();
    test_login_success();
    test_login_fail();

    printf("\nAll tests passed\n");
    return 0;
}