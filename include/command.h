#ifndef __COMMAND_COMMAND_H
#define __COMMAND_COMMAND_H

#include <string>
#include <vector>
#include <iostream>

#include "parameter.h"

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

            matchArguments(argc, argv);
        }

        /**
         * Destructor. Releases allocated memory.
         */
        ~Command() {
            for (Parameter * parameter : parameters) {
                delete parameter;
            }
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
        }
    };
}

#endif /* __COMMAND_COMMAND_H */
