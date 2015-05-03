#include <iostream>

#include "argument.h"

using namespace std;
using namespace command;

#define VALUE "567890.1234"

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
    else {
        cout << "Argument class do not understand float values\n";
        return 1;
    }

    if (test == std::stof(VALUE)) {
        cout << "Argument class handles float values\n";
        return 0;
    }

    cout << "Argument class do not handle float values\n";


    return 1;
}
