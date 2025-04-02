#include "argument_parser.hpp"
#include "file_operations.hpp"

enum Scenario { EMPTY_RUN, FILE_CHECK };

using namespace std;

constexpr int MIN_ARGUMENT_NUMBER = 2;
constexpr int NORMAL_ARGUMENT_NUMBER = 2;

int empty_run() {
    string test = "abcd";
    return 0;
}

int file_check() {
    ifstream file;
    string line;

    string shaders1("test_file.txt");

    file.open(shaders1);
    if (!file.is_open()) {
        cout << "Error while opening the file:" << shaders1 << endl;
        return -1;
    }
    auto line_counter = 0;
    while (getline(file, line)) {
        cout << "file[" << line_counter << "] = " << line;
    }
    file.close();
    return 0;
}

int main(int argc, char **argv) {
    if (argc < MIN_ARGUMENT_NUMBER) {
        cout << "Missing Scenario argument" << endl;
        return -1;
    }
    if (argc > NORMAL_ARGUMENT_NUMBER) {
        cout << "Many argument provided, printing them:" << endl;
        print_all_args(argc, argv);
        return 0;
    }
    auto scenar = static_cast<Scenario>(stoi(argv[1]));
    switch (scenar) {
    case EMPTY_RUN:
        cout << "empty_run" << endl;
        return empty_run();
        break;

    case FILE_CHECK:
        cout << "file_check" << endl;
        return file_check();
        break;

    default:
        cout << "Unplanned Scenario, printing all args" << endl;
        print_all_args(argc, argv);
        break;
    }
    return 0; // technically unreachable
}