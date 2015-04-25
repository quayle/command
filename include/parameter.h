#ifndef __COMMAND_PARAMETER_H
#define __COMMAND_PARAMETER_H

#include <string>

#include "descriptive.h"
#include "callable.h"

namespace command {
    /**
     * Class responsible for handling commandline arguments.
     * Arguments are required,x non-named parameters of program.
     *
     * Example:
     *  ./myprog ARGUMENT
     */
    class Parameter : public Descriptive {
    public:
        typedef class Parameter Type;
        /**
         * Default constructor.
         *
         * @param description Description of current Argument
         */
        Parameter(std::string description)
            : Descriptive(description) {
        }
        virtual ~Parameter() {}

        virtual void handle() {
            std::cout << "Parameter::handle()" << std::endl;
        };
    };
}

#endif /* __COMMAND_PARAMETER_H */
