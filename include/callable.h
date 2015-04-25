#ifndef __COMMAND_CALLABLE_H
#define __COMMAND_CALLABLE_H

#include <string>

namespace command {
    /**
     * Callable behaviour class.
     */
    template<typename ArgumentType>
    class Callable {
    protected:
        /**
         * Function handling user Arguments
         */
        void (*func)(ArgumentType);

    public:
        /**
         * Default constructor.
         *
         * @param function Function that will be invoked
         */
        Callable(void (*function)(ArgumentType))
            : func(function) {
        }
        virtual ~Callable() { }

    protected:
        /**
         * Executes command binded with argument
         *
         * @param value Value passed to program argument
         */
        void call(ArgumentType value) {
            this->func(value);
        }
    };
}

#endif /* __COMMAND_DESCRIPTIVE_H */
