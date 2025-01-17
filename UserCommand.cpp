#include "UserCommand.h"


UserCommand::UserCommand()
{
    dbconnection = DBConnection::getInstance();
    conn = dbconnection->getConnection();
}




