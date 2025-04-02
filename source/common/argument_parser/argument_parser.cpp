#include "argument_parser.hpp"

using namespace std;

void print_all_args(int argc, char *argv[]) {
    for (int argn = 0; argn < argc; argn++) {
        cout << "[" << argn << "] = " << argv[argn] << endl;
    }
}

ArgumentParser::ArgumentParser(bool has_default_args) {
    if (has_default_args) {
        add_expected_argument("--help", "-h", ArgumentType::BOOL);
        add_expected_argument("--version", "-V", ArgumentType::BOOL);
    }
}

std::map<int, string> ArgumentParser::parse(const int argc,
                                            const char *argv[]) {
    if (argc > ArgumentParser::MAX_ARG) {
        throw std::runtime_error("Too many arguments provided: " + argc);
    }

    std::map<int, string> out;
    for (int argn = 0; argn < argc; argn++) {
        out.insert({argn, argv[argn]});
    }
    return out;
}

void ArgumentParser::add_expected_argument(string long_name, string short_name,
                                           ArgumentType type) {
    expected_arguments.push_back(Argument(long_name, short_name, type));
}
