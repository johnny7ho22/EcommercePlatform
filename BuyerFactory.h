#pragma once

#include "UserFactory.h"
#include "Buyer.h"

class BuyerFactory: public UserFactory
{
public:
    User* createUser(int id, string name, int age, int role, string password);
};