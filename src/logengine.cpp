#include "includes/logengine.h"

std::string LogEngine::getLogFile()
{
    return current_log_file;
}


bool LogEngine::setLogFile(const std::string &log_file)
{
    current_log_file = log_file;
    return true;
}

bool LogEngine::RecieveNotification()
{
    return false;
}

LogEngine::~LogEngine()
{
    puts("Log Engine destroyed");
}

LogEngine::LogEngine() : current_log_file("debug.log")
{
}


///////////////////////////////////////////////////////////////////////////////


bool NullLogEngine::Log(std::string InputMessage, std::deque<std::string> &Results)
{
    puts(InputMessage.c_str());
    Results.push_back("Null Log Engine");
    return false;
}

bool NullLogEngine::RecieveNotification()
{
    puts("Log Engine created");
    return false;
}


///////////////////////////////////////////////////////////////////////////////


bool FileLogging::Log(std::string InputMessage, std::deque<std::string> &Results)
{
    if (!out.is_open())
    {
        out.open(getLogFile().c_str(), std::ios::binary | std::ios::out | std::ios::trunc);
    }

    out << InputMessage << std::endl;
    Results.push_back("\"" + InputMessage + "\" added to log.");

    out.flush();

    return 1;
}

bool FileLogging::RecieveNotification()
{
    puts("File Logging enabled.\n");
    return true;
}

FileLogging::~FileLogging()
{
    puts("Closing Logfile\n");
    out.flush();
    out.close();
}

FileLogging::FileLogging()
{
}


///////////////////////////////////////////////////////////////////////////////


bool ConsoleLogging::Log(std::string InputMessage, std::deque<std::string> &Results)
{
    std::string new_line = InputMessage;
    new_line += "\n";

    fputs(new_line.c_str(), stderr);
    Results.push_back("\"" + InputMessage + "\" added to log.");

    return 1;
}

bool ConsoleLogging::RecieveNotification()
{
    puts("Console Logging enabled.\n");
    return true;
}

ConsoleLogging::ConsoleLogging()
{
}

ConsoleLogging::~ConsoleLogging()
{
    puts("Deleting ConsoleLogging service...\n");
}
