#include "BuyerFactory.h"

User* BuyerFactory::createUser(int id, string name, int age, int role, string password)
{
    return new Buyer(id,name,age,role,password);
}
