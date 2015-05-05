#include <iostream>
#include <string>

#include "option.h"
#include "argument.h"
#include "required.h"
#include "command.h"

using namespace command;

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
    Command command(argc, argv, {
//         new Argument<std::string>("File path", [](std::string value)->void { std::cout << "Hello from lambda " << value << std::endl; }),
        new Required(new Argument<bool>("File path", argument_function)),
        new Option<std::string>("f", "Optional file", option_function),
        new Option<void>("h", "Help", void_function)
    });

    return 0;
}