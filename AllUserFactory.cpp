#include "AllUserFactory.h"


User* BuyerFactory::createUser(int id, string name, int age, int role, string password)
{
    return new Buyer(id,name,age,role,password);
}

User* SellerFactory::createUser(int id, string name, int age, int role, string password)
{
    return new Seller(id,name,age,role,password);
}

User* AdminFactory::createUser(int id, string name, int age, int role, string password)
{
    return new Admin(id,name,age,role,password);
}

