#include <iostream>
#include <string>

#include "option.h"
#include "argument.h"
#include "command.h"


int main(int argc, char *argv[]) {
    command::Command command(argc, argv, {
        new command::Argument<std::string>("File path", [](std::string value)->void { std::cout << "Hello from lambda " << value << std::endl; }),
        new command::Argument<std::string>("File path", [](std::string value)->void { std::cout << "Hello from lambda " << value << std::endl; }),
        new command::Argument<std::string>("File path", [](std::string value)->void { std::cout << "Hello from lambda " << value << std::endl; }),
        new command::Argument<std::string>("File path", [](std::string value)->void { std::cout << "Hello from lambda " << value << std::endl; }),
        new command::Argument<std::string>("File path", [](std::string value)->void { std::cout << "Hello from lambda " << value << std::endl; })
    });

    return 0;
}