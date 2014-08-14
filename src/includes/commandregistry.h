#ifndef COMMANDREGISTRY_H
#define COMMANDREGISTRY_H

#include <string>
#include <deque>
#include <memory>
#include "logengine.h"
#include "command.h"

class CommandRegistry
{
    public:
        /** Default constructor */
        CommandRegistry();
        /** Default destructor */
        virtual ~CommandRegistry();

        /** Access _Key
         * \return The current value of _Key
         */
        std::string GetKey(const int &ID);
        /** Access _Value
         * \return The current value of _Value
         */
        std::shared_ptr<ICommand> GetCommand(const std::string &key_name);

        /** Access _LogValue
         * \return The current value of _LogValue
         */
        std::shared_ptr<LogEngine> GetLogEngine(const std::string &key_name);

        /** Pushback Key/Value Pair
         * \param val New value to set
         */
        void push_back(const std::string &key_name, std::shared_ptr<ICommand> value_command);

        /** Pushback Key/Value Pair
         * \param val New value to set
         */
        void push_back(const std::string &key_name, ICommand* value_command);

        /** Pushback Key/Value Pair
         * \param val New value to set
         */
        void push_back(const std::string &key_name, std::shared_ptr<LogEngine> value_command);

        /** Pushback Key/Value Pair
         * \param val New value to set
         */
        void push_back(const std::string &key_name, LogEngine* value_command);
    protected:
    private:
        std::vector<std::string> _Key; //!< Member variable "_Key"
        std::vector<std::shared_ptr<ICommand> > _Value; //!< Member variable "_Value"
        std::vector<std::shared_ptr<LogEngine> > _LogValue; //!< Member variable "_LogValue"


        /** Copy constructor
         *  \param other Object to copy from
         */
        CommandRegistry(const CommandRegistry& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        CommandRegistry& operator=(const CommandRegistry& other);
};

#endif // COMMANDREGISTRY_H
