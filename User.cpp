#include "User.h"
   
User::User()
{
    dbconnection = DBConnection::getInstance();
    conn = dbconnection->getConnection();
}

User::~User()
{
}