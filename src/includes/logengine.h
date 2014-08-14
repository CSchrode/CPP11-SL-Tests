#ifndef LOGENGINE_H
#define LOGENGINE_H

#include <string>
#include <deque>
#include <vector>
#include <iostream>
#include <fstream>

class LogEngine
{
public:
    virtual bool Log(std::string InputMessage, std::deque<std::string> &Results) = 0;
    virtual std::string getLogFile();
    virtual bool setLogFile(const std::string &log_file);
    virtual bool RecieveNotification();

    LogEngine();
    virtual ~LogEngine();

protected:
    std::string current_log_file;
};


///////////////////////////////////////////////////////////////////////////////


class NullLogEngine : public LogEngine
{
public:
    bool Log(std::string InputMessage, std::deque<std::string> &Results);
    bool RecieveNotification();
};


///////////////////////////////////////////////////////////////////////////////


class FileLogging : public LogEngine
{
public:
    bool Log(std::string InputMessage, std::deque<std::string> &Results);

    bool RecieveNotification();

    FileLogging();
    virtual ~FileLogging();

private:
    std::ofstream out;
};


///////////////////////////////////////////////////////////////////////////////


class ConsoleLogging : public LogEngine
{
public:
    bool Log(std::string InputMessage, std::deque<std::string> &Results);

    bool RecieveNotification();

    ConsoleLogging();

    virtual ~ConsoleLogging();
};

#endif // LOGENGINE_H
