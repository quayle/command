#ifndef __COMMAND_ARGUMENT_H
#define __COMMAND_ARGUMENT_H

#include <string>

#include <command/descriptive.h>

namespace command {
    /**
     * Class responsible for handling commandline arguments.
     * Arguments are required non-named parameters for program.
     *
     * Example:
     *  ./myprog ARGUMENT
     */
    template<typename ArgumentType>
    class Argument : public Descriptive {
    public:
        typedef void (*)(ArgumentType) FunctionType;

    protected:
        /**
         * Function handling user Arguments
         */
        FunctionType function;

    public:
        /**
         * Default constructor.
         *
         * @param description Description of current Argument
         * @param function Function used to handle current Argument.
         */
        Argument(std::string description, FunctionType function)
            : Descriptive(description), function(function) {
        }

        /**
         * Executes command binded with argument
         *
         * @param value Value passed to program argument
         */
        void run(ArgumentType value) {
            this->function(value);
        }
    };
}

#endif /* __COMMAND_ARGUMENT_H */
