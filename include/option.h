#ifndef __COMMAND_OPTION_H
#define __COMMAND_OPTION_H

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
        : Argument<OptionType> {
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
        Argument(std::string name, std::string description, FunctionType function)
            : name(name), Argument<OptionType>(description, function) {
        }
    };
}

#endif /* __COMMAND_OPTION_H */
