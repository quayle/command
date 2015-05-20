# Command

C++ library for handling command line arguments.

## Installation

### debian package

    $ wget https://github.com/quayle/command/releases/download/v0.2.1-deb/command_0.2.1_all.deb
    $ sudo dpkg -i command_0.2.1_all.deb

### from sources

You will need to have autotools installed (automake, autoconf, ...)

    $ ./autogen.sh
    $ ./configure
    $ make
    $ sudo make install

## Configuration

You need to enable c++11 support in your compiler. You can achieve that in
g++ and clang++ by adding `-std=c++11` compilation flag.

As this is header-only library, you don't need any additional steps.

## Usage

example.cpp:

    #include <iostream>
    #include <command/command.h>
    #include <command/option.h>

    using namespace command;

    int main(int argc, char *argv[]) {
        try {
            Command command(argc, argv, {
                new Option<void>("-h", "Help", [](void) { std::cout << "Help information\n"; })
            });
        }
        catch(const std::exception & e) {
            return 1;
        }

        return 0;
    }

Now program can be compiled & run using following commands:

    $ g++ -std=c++11 example.cpp
    $ ./a.out -h
    Help information

## Documentation

Current documentation can be found at:
http://dlugolecki.net.pl/software/command/docs/

If for some reason it is unavailable, you can build it yourself. The only
requirement is to have [Doxygen](http://www.doxygen.org/) installed when `make` command is invoked.
