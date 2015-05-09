#ifndef __COMMAND_EXCEPTION_MISSING_OPTION_VALUE_H
#define __COMMAND_EXCEPTION_MISSING_OPTION_VALUE_H

#include <stdexcept>
#include <string>

namespace command {

/**
 * Helper template class used for releasing resources.
 */
class MissingOptionValue : public std::invalid_argument {
private:
    std::string message;
public:
    explicit MissingOptionValue(const std::string& what_arg) :
        std::invalid_argument(what_arg), message(what_arg) { }

    explicit MissingOptionValue(const char* what_arg) :
        std::invalid_argument(what_arg), message(what_arg) { }

    virtual const char* what() const throw() {
        return message.c_str();
    }
};

}

#endif /* __COMMAND_EXCEPTION_MISSING_OPTION_VALUE_H */
