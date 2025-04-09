/**
 * @file argument_parser.hpp
 * @author Axel J.
 * @brief Argument parser class and helper classes.
 *
 * Constrains: shall only use C++ STL
 * Inspiration from: https://docs.python.org/3/library/argparse.html
 * @version 0.1
 * @date 2025-04-02
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T> class Argument {
  protected:
    string long_name;
    T value;

  public:
    Argument(string long_name, T value) : long_name(long_name), value(value) {}
    ~Argument() = default;
    T getValue() { return value; };
};

template <typename T> class VerbosedArgument : public Argument<T> {
  private:
    string shortname;

  public:
    string description;
    VerbosedArgument(string long_name, T value, string short_name,
                     string description)
        : Argument<T>(long_name, value), shortname(shortname),
          description(description) {}
    ~VerbosedArgument() = default;
};

class ArgumentParser {
  private:
    static constexpr int MAX_ARG = 64;
    string program_name;
    string description;
    string epilog = "";
    std::map<int, string> raw_arguments;
    std::vector<string> known_arguments;

  public:
    ArgumentParser(string program_name = "program", string description = "",
                   string epilog = "")
        : program_name(program_name), description(description),
          epilog(epilog) {};
    ~ArgumentParser() = default;
    std::map<int, string> parse_args(const int argc, const char *argv[]);
    void add_argument(string long_name);
    void add_argument(string long_name, string short_name);
    void print_help();
};

void print_all_args(int argc, char *argv[]);