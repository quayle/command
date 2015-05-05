#ifndef __COMMAND_REQUIRED_H
#define __COMMAND_REQUIRED_H

#include "parameter.h"

namespace command {
    /**
     * Required Parameter decorator. Makes passed Parameters treated as required
     */
    class Required : public Parameter {
    protected:
        /**
         * Parameter which will be treated as required
         */
        Parameter * parameter;

    public:
        /**
         * Default constructor.
         *
         * @param parameter Parameter which will be treated as required
         */
        Required(Parameter * parameter)
            : Parameter(parameter->describe()), parameter(parameter) {
        }

        /**
         * Default destructor. Releases allocated memory
         */
        virtual ~Required() {
            delete parameter;
        }

        /**
         * Method used for handling method calls to linked Parameter
         */
        virtual void handle() {
            parameter->handle();
        }

        /**
         * Method used for checking if the given user value is understandable by
         * parameter.
         *
         * @param value value from argv to check against
         */
        virtual bool understand(const std::string & value) {
            return parameter->understand(value);
        }

        /**
         * Indicates if current Parameter is required
         */
        virtual bool isRequired() {
            return true;
        };

        /**
         * Indicates if current Parameter is already used
         */
        virtual bool isUsed() {
            return parameter->isUsed();
        };
    };
}

#endif /* __COMMAND_PARAMETER_H */
