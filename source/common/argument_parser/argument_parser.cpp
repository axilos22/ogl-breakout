#include "argument_parser.hpp"

using namespace std;

void print_all_args(int argc, char *argv[]) {
    for (int argn = 0; argn < argc; argn++) {
        cout << "[" << argn << "] = " << argv[argn] << endl;
    }
}

std::map<int, string> ArgumentParser::parse_args(const int argc,
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

void ArgumentParser::add_argument(string long_name) {
    known_arguments.push_back(long_name);
}

void ArgumentParser::add_argument(string long_name, string short_name) {
    known_arguments.push_back(short_name);
    add_argument(long_name);
}

void ArgumentParser::print_help() {
    stringstream out;
    out << "usage: " << this->program_name << endl;
    out << endl;
    for (auto &arg : known_arguments) {
        out << arg << endl;
    }
    out << endl;
    out << this->epilog << endl;
    cout << out.str();
}
