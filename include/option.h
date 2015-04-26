#ifndef __COMMAND_OPTION_H
#define __COMMAND_OPTION_H

#include <string>

#include "argument.h"

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
        : public Argument<OptionType> {
    public:
//         typedef typename Argument<OptionType, Lambda>::FunctionType FunctionType;
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
            : name(name), Argument<OptionType>(description, function) {
        }
        virtual ~Option() { }

        virtual void handle() {
            std::cout << "Option::handle()" << std::endl;
            this->call(std::string("O"));
        }
    };
}

#endif /* __COMMAND_OPTION_H */
