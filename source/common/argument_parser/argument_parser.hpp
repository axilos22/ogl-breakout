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
#include <string>

using namespace std;

enum class ArgumentType { BOOL, NUMERIC, TEXT };

class Argument {
  protected:
    string long_name;
    string short_name;
    ArgumentType type;

  public:
    Argument(string long_name, string short_name,
             ArgumentType type = ArgumentType::BOOL)
        : long_name(long_name), short_name(short_name), type(type) {}
    ~Argument() = default;
};

template <typename T> class ValueArgument : public Argument {
  private:
    T value;

  public:
    ValueArgument(string long_name, string short_name, T value)
        : Argument(long_name, short_name), value(value) {}
    ~ValueArgument() = default;
    auto getValue();
};

/**
 * @brief Flag are declarative arguments which are present or not.
 * Their value are switching to true when they are detected in the command line.
 */
class FlagArgument : ValueArgument<bool> {};

/**
 * @brief Class for numerical argument
 *
 * @tparam N can be either uint, int, float, double
 */
template <typename N> class NumericalArgument : ValueArgument<N> {};

class ArgumentParser {
  private:
    static constexpr int MAX_ARG = 64;
    std::list<Argument> expected_arguments;

  public:
    ArgumentParser(bool has_default_args = true);
    ~ArgumentParser() = default;
    std::map<int, string> parse(const int argc, const char *argv[]);
    void add_expected_argument(string long_name, string short_name,
                               ArgumentType type);
};

void print_all_args(int argc, char *argv[]);

template <typename T> inline auto ValueArgument<T>::getValue() { return value; }
