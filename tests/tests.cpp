#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

#include "../src/includes/servicelocator.h"
#include "../src/includes/commandregistry.h"
#include "../src/includes/command.h"
#include "../src/includes/logengine.h"

std::shared_ptr<LogEngine> LogLocator::service_ = NULL;

int main()
{
    Services::initialize();

    CommandRegistry Test;
    std::shared_ptr<LogEngine> Null1(new ConsoleLogging);
    std::shared_ptr<LogEngine> Null2(new FileLogging);
    std::shared_ptr<LogEngine> Null3(new NullLogEngine);
    Test.push_back("console", Null1);
    Test.push_back("file", Null2);
    Test.push_back("null", Null3);

    std::deque<std::string> Results;

    LogLocator::provide(Test.GetLogEngine("console"));
    LogLocator::GetLogEngine()->Log("Test 1", Results);
    assert(Results.at(0) == "\"Test 1\" added to log.");

    LogLocator::provide(Test.GetLogEngine("file"));
    LogLocator::GetLogEngine()->Log("Test 2", Results);
    assert(Results.at(1) == "\"Test 2\" added to log.");

    LogLocator::provide(Test.GetLogEngine("null"));
    Services::GetLogEngine()->Log("Test 3", Results);
    assert(Results.at(2) == "Null Log Engine");

    LogLocator::provide(Test.GetLogEngine("non-existant"));
    Services::GetLogEngine()->Log("Test 1", Results);
    assert(Results.at(3) == "Null Log Engine");

    LogLocator::provide(Test.GetLogEngine("file"));
    LogLocator::GetLogEngine()->Log("Test 2", Results);
    assert(Results.at(4) == "\"Test 2\" added to log.");

    return 0;
}
