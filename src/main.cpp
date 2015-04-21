
int main() {
    command::Command command(argc, argv, {
        command::Option<std::string>("f", "File path", [](std::string value)->void { cout << "Sth: " << value << endl; }),
        command::Argument<std::string>("File path", []()->void { cout << "Sth: " << value << endl; }),
        command::Option<void>("help", "Help description", [](void)->void { cout << "Sth: " << value << endl; }),
        command::Option<void>("verbose", "Verbose option description", &myClass->verbose)
    });

    return 0;
}