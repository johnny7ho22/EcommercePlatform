#include "AdminFactory.h"

User* AdminFactory::createUser(int id, string name, int age, int role, string password)
{
    return new Admin(id,name,age,role,password);
}
