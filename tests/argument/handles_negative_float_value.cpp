#include <iostream>

#include "argument.h"

using namespace std;
using namespace command;

#define VALUE "-567890.1234"

typedef float ArgumentType;

ArgumentType test;

void function(ArgumentType value) {
    test = value;
}

int main() {
    Argument<ArgumentType> argument("Argument as float", function);

    if (argument.understand(VALUE)) {
        argument.handle();
    }

    if (test == std::stof(VALUE)) {
        cout << "Argument class handles negative float values\n";
        return 0;
    }

    cout << "Argument class do not handle negative float values\n";


    return 1;
}
