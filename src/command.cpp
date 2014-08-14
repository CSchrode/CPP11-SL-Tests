#include "includes/command.h"

bool ICommand::RecieveNotification()
{
    return false;
}

ICommand::~ICommand()
{
}


///////////////////////////////////////////////////////////////////////////////


bool NullCommand::Run(std::string InputMessage, std::deque<std::string> &Results)
{
    return false;
}
