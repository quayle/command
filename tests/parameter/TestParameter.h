#include "parameter.h"


class TestParameter : public command::Parameter {
public:
    TestParameter(const std::string & description) : Parameter(description) { }

    virtual void handle() { }
    virtual bool understand(const std::string & argVal) { }
};