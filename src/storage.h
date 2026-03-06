#ifndef STORAGE_H
#define STORAGE_H

#include "auth.h"

int save_user(User user);
int find_user(const char *username, User *user);
void set_db_file(const char *filename);

#endif