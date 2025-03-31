#include "file_operations.hpp"

using namespace std;

void print_all_lines(string path) {
    ifstream file;
    file.open(path);
    string line;
    while(getline(file, line)) {
        cout << line << endl;
    }
}