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
    LogEngine* Null1 = new NullLogEngine;
    std::shared_ptr<LogEngine> Null2(new NullLogEngine);
    std::shared_ptr<LogEngine> Null3(new NullLogEngine);
    Test.push_back("null", Null1);
    Test.push_back("null_", Null2);
    Test.push_back("null-", Null3);

    std::deque<std::string> Results;

    LogLocator::provide(Test.GetLogEngine("null"));
    LogLocator::GetLogEngine()->Log("Test 1", Results);
    assert(Results.at(0) == "Null Log Engine");

    LogLocator::provide(Test.GetLogEngine("null-"));
    LogLocator::GetLogEngine()->Log("Test 2", Results);
    assert(Results.at(1) == "Null Log Engine");

    LogLocator::provide(Test.GetLogEngine("null_"));
    Services::GetLogEngine()->Log("Test 3", Results);
    assert(Results.at(2) == "Null Log Engine");

    LogLocator::provide(Test.GetLogEngine("null"));
    Services::GetLogEngine()->Log("Test 4", Results);
    assert(Results.at(3) == "Null Log Engine");
    return 0;
}
