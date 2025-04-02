#include "argument_parser.hpp"

enum Scenario {
    CONSTRUCTOR,
    NO_ARG,
    ONE_ARG,
    TWO_ARGS,
    MANY_ARGS,
    TOO_MANY_ARGS
};

using namespace std;

constexpr int MIN_ARGUMENT_NUMBER = 2;

int constructor() {
    ArgumentParser parser;
    return 0;
}

int no_arg() {
    ArgumentParser parser;
    string expected = "basicProgramName";
    int argc = 1;
    const char *argv[] = {expected.c_str(), ""};
    auto parsed_args = parser.parse(argc, argv);

    return expected.compare(parsed_args[argc - 1]);
}

int one_arg() {
    ArgumentParser parser;
    string expected = "--version";
    int argc = 2;
    const char *argv[] = {"basicProgramName", expected.c_str()};
    auto parsed_args = parser.parse(argc, argv);

    return expected.compare(parsed_args[argc - 1]);
}

int two_arg() {
    ArgumentParser parser;
    string expected = "--help";
    int argc = 3;
    const char *argv[] = {"basicProgramName", "--version", expected.c_str()};
    auto parsed_args = parser.parse(argc, argv);

    return expected.compare(parsed_args[argc - 1]);
}

int many_arg() {
    ArgumentParser parser;
    string expected = "--boiz";
    int argc = 5;
    const char *argv[] = {"basicProgramName", "--version", "make", "some",
                          expected.c_str()};
    auto parsed_args = parser.parse(argc, argv);

    return expected.compare(parsed_args[argc - 1]);
}

int too_many_arg() {
    ArgumentParser parser;
    string expected = "--boiz";
    int argc = 255;
    const char *argv[] = {
        "basicProgramName", "--version", "make", "some", "noise",
        expected.c_str()};
    try {
        auto parsed_args = parser.parse(argc, argv);
        std::cout << "No Exception caught!" << std::endl;
        return -1;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc < MIN_ARGUMENT_NUMBER) {
        cout << "Missing Scenario argument" << endl;
        return -1;
    }
    auto scenar = static_cast<Scenario>(stoi(argv[1]));
    switch (scenar) {
    case CONSTRUCTOR:
        return constructor();
        break;

    case NO_ARG:
        return no_arg();
        break;

    case ONE_ARG:
        return one_arg();
        break;

    case TWO_ARGS:
        return two_arg();
        break;

    case MANY_ARGS:
        return many_arg();
        break;

    case TOO_MANY_ARGS:
        return too_many_arg();
        break;

    default:
        cout << "Unplanned Scenario, printing all args" << endl;
        print_all_args(argc, argv);
        break;
    }
    return 0; // technically unreachable
}