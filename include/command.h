#ifndef __COMMAND_COMMAND_H
#define __COMMAND_COMMAND_H

#include <string>
#include <vector>
#include <typeinfo>

#include "parameter.h"
#include "exception/missingRequiredParameter.h"

namespace command {
    /**
     * Main class for handling user passed parameters from command line.
     */
    class Command {
    protected:
        std::vector<Parameter *> parameters;
    public:
        /**
         * Default constructor.
         *
         * @param argc passed to the main function
         * @param argv passed to the main function
         * @param params initializer_list containing Parameter handlers
         *      responsible for correctly handle user data.
         */
        Command(unsigned int argc, char *argv[], std::initializer_list<Parameter *> params)
            : parameters(params) {

            try {
                matchArguments(argc, argv);
            }
            catch(const std::invalid_argument & exception) {
                releaseMemory();
                throw;
            }
            catch(const std::logic_error & exception) {
                releaseMemory();
                throw;
            }
        }

        /**
         * Destructor. Releases allocated memory.
         */
        ~Command() {
            releaseMemory();
        }
    protected:
        /**
         * Matches user passed arguments with available parameter handlers.
         */
        void matchArguments(unsigned int argc, char *argv[]) {
            for (unsigned int i = 1; i < argc; i++) {
                for(Parameter *param : parameters) {
                    if (param->understand(argv[i])) {
                        param->handle();
                        break;
                    }
                }
            }
            for(Parameter *param : parameters) {
                if (param->isRequired() && !param->isUsed()) {
                    throw MissingRequiredParameter(param->describe() + " is required but it was not passed");
                }
            }
        }

        /**
         * Releases acquired memory
         */
        void releaseMemory() {
            for (Parameter * parameter : parameters) {
                if (parameter != NULL) {
                    delete parameter;
                }
            }
            parameters.clear();
            parameters.shrink_to_fit();
        }
    };
}

#endif /* __COMMAND_COMMAND_H */
