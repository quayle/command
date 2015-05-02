#ifndef __COMMAND_DESCRIPTIVE_H
#define __COMMAND_DESCRIPTIVE_H

#include <string>

namespace command {
    /**
     * Descriptive behaviour class.
     */
    class Descriptive {
        std::string description;
    public:
        /**
         * Default constructor.
         *
         * @param description Description
         */
        Descriptive(const std::string& description)
            : description(description) {
        }

        /**
         * Returns description of the current class.
         *
         * @return provided description for the class
         */
        std::string describe() {
            return description;
        }
    };
}

#endif /* __COMMAND_DESCRIPTIVE_H */
