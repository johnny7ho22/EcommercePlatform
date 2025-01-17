#pragma once

#include "UserFactory.h"
#include "Admin.h"

class AdminFactory: public UserFactory
{
public:
    User* createUser(int id, string name, int age, int role, string password);
};