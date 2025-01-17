#pragma once
#include "UserFactory.h"
#include "Buyer.h"
#include "Seller.h"
#include "Admin.h"


class BuyerFactory: public UserFactory
{
public:
    User* createUser(int id, string name, int age, int role, string password);
};


class SellerFactory: public UserFactory
{
public:
    User* createUser(int id, string name, int age, int role, string password);
};


class AdminFactory: public UserFactory
{
public:
    User* createUser(int id, string name, int age, int role, string password);
};