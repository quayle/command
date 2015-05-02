#ifndef __COMMAND_ARGUMENT_H
#define __COMMAND_ARGUMENT_H

#include <string>
#include <iostream>

#include "parameter.h"
#include "callable.h"

namespace command {
    /**
     * Class responsible for handling commandline arguments.
     * Arguments are required,x non-named parameters of program.
     *
     * Example:
     *  ./myprog ARGUMENT
     */
    template<typename ArgumentType>
    class Argument : public Parameter, public Callable<ArgumentType> {
    public:
        typedef class Argument Type;
        /**
         * Default constructor.
         *
         * @param description Description of current Argument
         * @param function Function used to handle current Argument.
         */
        Argument(const std::string & description, void (*function)(ArgumentType))
            : Parameter(description), Callable<ArgumentType>(function) {
        }
        virtual ~Argument() { }

        virtual void handle() {
            this->call(std::string("A"));
        }

        virtual bool understand(const std::string &) {
            return false;
        }
    };
}

#endif /* __COMMAND_ARGUMENT_H */
