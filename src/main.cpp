#include <iostream>
#include <string>

#include "option.h"
#include "argument.h"
#include "command.h"

void argument_function(bool a) {
    std::cout << "Argument: " << a << std::endl;
}

void option_function(std::string a) {
    std::cout << "Help function " << a << std::endl;
}

void void_function(void) {
    std::cout << "Void function " << std::endl;
}

int main(int argc, char *argv[]) {
    command::Command command(argc, argv, {
//         new command::Argument<std::string>("File path", [](std::string value)->void { std::cout << "Hello from lambda " << value << std::endl; }),
        new command::Argument<bool>("File path", argument_function),
        new command::Option<std::string>("f", "Optional file", option_function),
        new command::Option<void>("h", "Help", void_function)
    });

    return 0;
}