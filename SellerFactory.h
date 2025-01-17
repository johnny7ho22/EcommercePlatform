#pragma once

#include "UserFactory.h"
#include "Seller.h"

class SellerFactory: public UserFactory
{
public:
    User* createUser(int id, string name, int age, int role, string password);
};