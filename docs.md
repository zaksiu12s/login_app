# How to run the app:

1. Open the project folder.
2. Compile the app (On Windows eg. (MinGW / MSYS2 / UCRT64)).

- MinGW: `gcc src/main.c src/auth.c src/storage.c -o app`

3. Run the app with app.exe file.

# How to run tests:

1. Open the project folder.
2. Compile the tests (On Windows eg. (MinGW / MSYS2 / UCRT64)).

- MinGW: `gcc tests/test_auth.c src/auth.c src/storage.c -o tests`

3. Run the app with tests.exe file.

## Prerequisites

- C compiler (e.g., gcc, clang) installed
- Optional: Visual Studio Code for editing
- Terminal / command line access
