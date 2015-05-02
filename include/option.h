#ifndef __COMMAND_OPTION_H
#define __COMMAND_OPTION_H

#include <string>

#include "parameter.h"

namespace command {
    /**
     * Class responsible for handling commandline options.
     * Options are non-required, named parameters of program.
     *
     * Example:
     *  ./myprog OptionName OptionValue
     */
    template<typename OptionType>
    class Option
        : public Parameter, public Callable<OptionType>  {
    protected:
        /**
         * Option name
         */
        std::string name;

    public:
        /**
         * Default constructor.
         *
         * @param name Name of the current Option
         * @param description Description of current Option
         * @param function Function used to handle current Option.
         */
        Option(std::string name, std::string description, void (*function)(OptionType))
            : Parameter(description), Callable<OptionType>(function) {
        }
        virtual ~Option() { }

        virtual void handle() {
            this->call(std::string("O"));
        }

        virtual bool understand(std::string argVal) {
            if (argVal.find(name) != std::string::npos) {
                return true;
            }

            return false;
        }
    };
}

#endif /* __COMMAND_OPTION_H */
