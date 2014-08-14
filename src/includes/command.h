#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <deque>

class ICommand
{
public:
    virtual bool Run(std::string InputMessage, std::deque<std::string> &Results) = 0;
    virtual bool RecieveNotification();

    virtual ~ICommand();
};

class NullCommand : public ICommand
{
public:
    bool Run(std::string InputMessage, std::deque<std::string> &Results);
};

#endif // COMMAND_H
