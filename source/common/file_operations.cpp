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

std::stringstream get_file_as_stringstream(const std::string &file_path) {
    std::ifstream file;
    std::stringstream buffer_lines;
    std::string line;

    file.open(file_path);
    while (std::getline(file, line)) {
        buffer_lines << line << "\n";
    }
    buffer_lines.str("");
    file.close();
    return buffer_lines;
}