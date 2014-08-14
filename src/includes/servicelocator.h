#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H

#include <memory>
#include "command.h"
#include "commandregistry.h"

class LogLocator
{
private:
    static std::shared_ptr<LogEngine> service_;

public:
    static void initialize();

    static std::shared_ptr<LogEngine> GetLogEngine();

    static void provide(std::shared_ptr<LogEngine> service);

    virtual ~LogLocator();
};

class Services
{
public:
    static std::shared_ptr<LogEngine> GetLogEngine();

    static void initialize();

    virtual ~Services();
};

#endif // SERVICELOCATOR_H
