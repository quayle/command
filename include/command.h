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
        unsigned int argc;
        std::vector<std::string> _argv;
        std::vector<Parameter *> args;
    public:
        /**
         * Default constructor.
         *
         * @param 
         * @param 
         * @param 
         */
        Command(unsigned int argc, char *argv[], std::initializer_list<Parameter *> params)
            : args(params) {
            for(Parameter *param : params) {
                param->handle();
            }
        }
        
        ~Command() {
            for (Parameter * parameter : args) {
                delete parameter;
            }
        }
    };
}

#endif /* __COMMAND_COMMAND_H */
