#pragma once

#include "UserCommand.h"

class UserCommandFactory
{
public:
    virtual UserCommand* createUserCommand(User* user, UserCommand* usercommand) = 0;
};