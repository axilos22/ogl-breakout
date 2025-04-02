#include "argument_parser.hpp"

using namespace std;

void print_all_args(int argc, char **argv) {
    for (int argn = 0; argn < argc; argn++) {
        cout << "[" << argn << "] = " << argv[argn] << endl;
    }
}
