#include <iostream>
#include <string>

#include "option.h"
#include "argument.h"
#include "command.h"

void some_function(bool a) {
    std::cout << "Some function " << a << std::endl;
}

void help_function(std::string a) {
    std::cout << "Some function " << a << std::endl;
}

int main(int argc, char *argv[]) {
    command::Command command(argc, argv, {
//         new command::Argument<std::string>("File path", [](std::string value)->void { std::cout << "Hello from lambda " << value << std::endl; }),
        new command::Argument<bool>("File path", some_function),
        new command::Option<std::string>("h", "Help", help_function)
    });

    return 0;
}