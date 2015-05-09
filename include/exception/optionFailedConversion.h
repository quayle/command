#ifndef __COMMAND_EXCEPTION_OPTION_FAILED_CONVERSION_H
#define __COMMAND_EXCEPTION_OPTION_FAILED_CONVERSION_H

#include <stdexcept>
#include <string>

namespace command {

/**
 * Helper template class used for releasing resources.
 */
class OptionFailedConversion : public std::invalid_argument {
protected:
    std::string message;
public:
    explicit OptionFailedConversion(const std::string& what_arg) :
        std::invalid_argument(what_arg), message(what_arg) { }

    explicit OptionFailedConversion(const char* what_arg) :
        std::invalid_argument(what_arg), message(what_arg) { }

    virtual const char* what() const throw() {
        return message.c_str();
    }
};

}

#endif /* __COMMAND_EXCEPTION_OPTION_FAILED_CONVERSION_H */
