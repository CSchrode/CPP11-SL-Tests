#include "includes/commandregistry.h"

/** Default constructor */
CommandRegistry::CommandRegistry()
{
}
/** Default destructor */
CommandRegistry::~CommandRegistry()
{
}

/** Access _Key
 * \return The current value of _Key
 */
std::string CommandRegistry::GetKey(const int &ID)
{
    return _Key.at(ID);
}
/** Access _Value
 * \return The current value of _Value
 */
std::shared_ptr<ICommand> CommandRegistry::GetCommand(const std::string &key_name)
{
    int position = 0;

    for (std::vector<std::string>::iterator iter = _Key.begin(); iter!=_Key.end(); iter++)
    {
        std::string buffer = *iter;
        if (buffer == key_name)
        {
            return _Value.at(position);
        }

        position++;
    }

    return std::shared_ptr<ICommand>(new NullCommand);
}

/** Access _LogValue
 * \return The current value of _LogValue
 */
std::shared_ptr<LogEngine> CommandRegistry::GetLogEngine(const std::string &key_name)
{
    int position = 0;

    for (std::vector<std::string>::iterator iter = _Key.begin(); iter!=_Key.end(); iter++)
    {
        std::string buffer = *iter;
        if (buffer == key_name)
        {
            return _LogValue.at(position);
        }

        position++;
    }

    return std::shared_ptr<LogEngine>(new NullLogEngine);
}

/** Pushback Key/Value Pair
 * \param val New value to set
 */
void CommandRegistry::push_back(const std::string &key_name, std::shared_ptr<ICommand> value_command)
{
    _Key.push_back(key_name);

    size_t ubound = _Key.size() - _Value.size() - 1;
    while(ubound > 0)
    {
        _Value.push_back(std::shared_ptr<ICommand>(new NullCommand));
        ubound--;
    }

    _Value.push_back(value_command);
}

/** Pushback Key/Value Pair
 * \param val New value to set
 */
void CommandRegistry::push_back(const std::string &key_name, ICommand* value_command)
{
    push_back(key_name, std::shared_ptr<ICommand>(value_command));
}

/** Pushback Key/Value Pair
 * \param val New value to set
 */
void CommandRegistry::push_back(const std::string &key_name, std::shared_ptr<LogEngine> value_command)
{
    _Key.push_back(key_name);

    size_t ubound = _Key.size() - _LogValue.size() - 1;
    while(ubound > 0)
    {
        _LogValue.push_back(std::shared_ptr<LogEngine>(new NullLogEngine));
        ubound--;
    }
    _LogValue.push_back(value_command);
}

/** Pushback Key/Value Pair
 * \param val New value to set
 */
void CommandRegistry::push_back(const std::string &key_name, LogEngine* value_command)
{
    push_back(key_name, std::shared_ptr<LogEngine>(value_command));
}
