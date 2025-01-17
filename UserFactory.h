#pragma once

#include "User.h"

class UserFactory
{
public:
    virtual User* createUser(int id, string name, int age, int role, string password) = 0;
};