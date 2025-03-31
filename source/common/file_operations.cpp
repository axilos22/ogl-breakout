#include "file_operations.hpp"

using namespace std;

void print_file_content(string path) {
    ifstream file;

    file.open(path);
    if (!file.is_open()) {
        cout << "Error while opening the file:" << path << endl;
        return;
    }

    auto line_counter = 0;
    string line;
    while (getline(file, line)) {
        cout << "file[" << line_counter << "] = " << line;
    }
    file.close();
}