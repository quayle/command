#ifndef __COMMAND_PARAMETER_H
#define __COMMAND_PARAMETER_H

#include <string>

#include "descriptive.h"
#include "callable.h"

namespace command {
    /**
     * Base class for all the Arguments and Options.
     *
     * Example:
     *  ./myprog ARGUMENT
     */
    class Parameter : public Descriptive {
    protected:
        /** Variable indicating if current Parameter was already used or not */
        bool used = false;

    public:
        typedef class Parameter Type;
        /**
         * Default constructor.
         *
         * @param description Description of current Argument
         */
        Parameter(const std::string & description)
            : Descriptive(description) {
        }

        virtual ~Parameter() { }

        /**
         * Method used for handling method calls linked with Argument or Option
         */
        virtual void handle() = 0;

        /**
         * Method used for checking if the given user value understandable for
         * parameter.
         */
        virtual bool understand(const std::string & ) = 0;

        /**
         * Indicates if current Parameter is required
         */
        virtual bool isRequired() {
            return false;
        };

        virtual bool isUsed() {
            return used;
        }
    };
}

#endif /* __COMMAND_PARAMETER_H */
