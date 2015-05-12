#include <iostream>
#include <string>

#include "option.h"
#include "argument.h"
#include "required.h"
#include "multiValue.h"
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
    try {
        Command command(argc, argv, {
//             new Argument<std::string>("File path", [](std::string value)->void { std::cout << "Hello from lambda " << value << std::endl; }),
            new Required(new MultiValue("-", new Argument<bool>("Input values", argument_function))),
            new MultiValue(",", new Option<std::string>("f", "Optional file", option_function)),
            new Option<void>("h", "Help", void_function)
        });

    }
    catch(const std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}