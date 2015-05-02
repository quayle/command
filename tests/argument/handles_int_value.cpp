#include <cstring>
#include <iostream>

#include "argument.h"

using namespace std;
using namespace command;

#define VALUE "1234567890"

typedef int ArgumentType;

ArgumentType test;

void function(ArgumentType value) {
    test = value;
}

int main() {
    Argument<ArgumentType> argument("Argument as int", function);

    if (argument.understand(VALUE)) {
        argument.handle();
    }

    if (test == std::stoi(VALUE)) {
        cout << "Argument class handles int values\n";
        return 0;
    }

    cout << "Argument class do not handle int values\n";

    return 1;
}
