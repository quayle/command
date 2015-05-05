#ifndef __COMMAND_OPTION_H
#define __COMMAND_OPTION_H

#include <string>
#include <sstream>
#include <stdexcept>

#include "parameter.h"

namespace command {
    /**
     * Class responsible for handling commandline options.
     * Options are non-required, named parameters of program.
     *
     * Example:
     *  ./myprog OptionName=OptionValue
     *  ./myprog -f=/some/file
     *  ./myprog --level=15
     */
    template<typename OptionType>
    class Option
        : public Parameter, public Callable<OptionType>  {
    public:
        typedef std::string OptionName;
    protected:
        /**
         * Current Option name
         */
        const OptionName name;

        /**
         * Current Option value
         */
        OptionType value;

        /** Variable indicating if current Option was already used or not */
        bool used = false;

    public:
        /**
         * Default constructor.
         *
         * @param name Name of the current Option
         * @param description Description of current Option
         * @param function Function used to handle current Option.
         */
        Option(const std::string & name, const std::string & description, void (*function)(OptionType))
            : Parameter(description), Callable<OptionType>(function), name(name) {
        }

        /**
         *
         */
        virtual ~Option() { }

        /**
         *
         */
        virtual void handle() {
            this->call(value);
        }

        /**
         * Method used for checking if Option understands given user value.
         * If so current Option is flagged as used and no more checks against
         * it will be done in future.
         *
         * Passed value should be in form of:
         *      OptionName=OptionValue
         *
         * If no equal sign is after OptionName part,
         * std::invalid_argument exception with appropriate message is thrown
         *
         * If conversion of OptionValue part to OptionType failed,
         * std::invalid_argument exception with appropriate message is thrown
         *
         * @param argv command line value against which test will be made.
         *  User value should be in format: OptionName=OptionValue.
         *
         * @return If passed argv succesfully detected OptionName part as a
         *  current option and its OptionValue part has been succesfully
         *  converted to OptionType, returns true and Option is set as used one.
         *  Otherwise returns false and can be used to check against next value.
         *
         * @throw std::invalid_argument when OptionName part has no equal sign
         *  after itself
         * @throw std::invalid_argument when OptionValue part failed conversion
         *  to OptionType
         */
        virtual bool understand(const std::string & argv)
            throw(std::invalid_argument) {

            if ((!used) && (argv.find(name) == 0)) {
                std::size_t pos = argv.find("=");

                if (pos != name.size()) {
                    throw std::invalid_argument("Option: " + name + " requires value but no one has been provided");
                }

                std::stringstream ss;
                ss << argv.substr(pos + 1);
                ss >> value;// memory leak? when is uncommented, and exception is
                            // thrown, valgrind shows e.g.:
                            //  possibly lost: 380 bytes in 7 blocks

                if (ss.fail()) {
                    throw std::invalid_argument("Value for option: " + name + " failed conversion to the required type");
                }

                used = true;
                return true;
            }
            return false;
        }
    };

    /**
     * Template class responsible for handling commandline options.
     * Options are non-required, named parameters of program.
     * This template specialization allows Options to work like switches.
     * It means that just named parameter is needed to invoke command. No value
     * is used.
     *
     * Example:
     *  ./myprog OptionName
     *  ./myprog -h
     *  ./myprog --help
     */
    template<>
    class Option<void>
        : public Parameter, public Callable<void>  {
    public:
        typedef std::string OptionName;
    protected:
        /**
         * Current Option name
         */
        const OptionName name;

        /** Variable indicating if current Option was already used or not */
        bool used = false;

    public:
        /**
         * Default constructor.
         *
         * @param name Name of the current Option
         * @param description Description of current Option
         * @param function Function used to handle current Option.
         */
        Option(const std::string & name, const std::string & description, void (*function)(void))
            : Parameter(description), Callable<void>(function), name(name) {
        }

        /**
         *
         */
        virtual void handle() {
            this->call();
        }

        /**
         * Method used for checking if Option understands given user value.
         * If so, current Option is flagged as used and no more checks against
         * it will be done in future.
         *
         * Passed value should be in form of:
         *      OptionName
         *
         * @param argv command line value against which test will be made.
         *  User value should be in format: OptionName.
         *
         * @return If passed argv succesfully detected OptionName returns true
         *  and Option is set as used one. Otherwise returns false and can be
         *  used to check against next value.
         */
        virtual bool understand(const std::string & argv) {
            if ((!used) &&
                (argv == name)) {
                used = true;
                return true;
            }
            return false;
        }
    };
}

#endif /* __COMMAND_OPTION_H */
