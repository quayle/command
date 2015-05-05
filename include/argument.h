#ifndef __COMMAND_ARGUMENT_H
#define __COMMAND_ARGUMENT_H

#include <string>
#include <sstream>
#include <iostream>

#include "parameter.h"
#include "callable.h"

namespace command {
    /**
     * Class responsible for handling commandline arguments.
     * Arguments are required, non-named parameters of program.
     * Accepts
     *
     * Example:
     *  ./myprog ARGUMENT
     *  ./myprog /path/to/file
     *  ./myprog "some argument"
     */
    template<typename ArgumentType>
    class Argument : public Parameter, public Callable<ArgumentType> {
    protected:
        /** Variable indicating if current Argument was already used or not */
        bool used = false;

        ArgumentType value;
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

        /**
         *
         */
        virtual ~Argument() { }

        /**
         *
         */
        virtual void handle() {
            this->call(value);
        }

        /**
         * Method used for checking if Argument understands user value.
         * If so current Argument is flagged as used and no more checks against
         * it will be done in future.
         *
         * \attention If conversion from passed value to ArgumentType is
         * impossible, it is ignored. It means that it is not understanded by
         * Argument.
         *
         * @param argv command line value against which test will be made.
         *
         * @return If passed argv is succesfully converted to ArgumentType,
         *  returns true and Argument is set as used one. If there was an error
         *  during conversion, method returns false and can be used to check
         *  against next value.
         */
        virtual bool understand(const std::string & argv) {
            if (!used) {
                std::stringstream ss;

                ss << argv;
                ss >> value;

                if (!ss.fail()) {
                    used = true;
                    return true;
                }
            }

            return false;
        }
    };
}

#endif /* __COMMAND_ARGUMENT_H */
