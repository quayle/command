#include <cstring>
#include <iostream>

#include "parameter.h"

using namespace std;
using namespace command;

#define STRING "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

class TestParameter : public Parameter {
public:
    TestParameter(std::string description) : Parameter(description) { }

    virtual void handle() { }
    virtual bool understand(std::string argVal) { }
};

int main() {
    TestParameter parameter(STRING);

    int cmp = strcmp(parameter.describe().c_str(), STRING);

    if (cmp == 0) {
        cout << "Parameter class is descriptive\n";
        return 0;
    }

    cout << "Parameter class changes provided description so is not descriptive\n";

    return 1;
}

