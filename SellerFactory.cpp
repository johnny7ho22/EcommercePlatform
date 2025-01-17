#include "SellerFactory.h"

User* SellerFactory::createUser(int id, string name, int age, int role, string password)
{
    return new Seller(id,name,age,role,password);
}
