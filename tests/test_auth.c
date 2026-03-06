#include <assert.h>
#include <stdio.h>
#include "../src/auth.h"

void test_registration()
{
    int result = register_user("testuser", "1234");
    assert(result == 1 || result == 0);
}

void test_login_success()
{
    register_user("loginuser", "pass");
    int result = login_user("loginuser", "pass");
    assert(result == 1);
}

void test_login_fail()
{
    int result = login_user("nosuchuser", "pass");
    assert(result == 0);
}

int main()
{
    printf("Running tests...\n");

    test_registration();
    test_login_success();
    test_login_fail();

    printf("All tests passed\n");
    return 0;
}