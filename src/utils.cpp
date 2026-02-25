#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "utils.hpp"

std::string read_file(const std::string& path) {
    std::ifstream file(path, std::ios::binary);

    if (!file) {
        throw std::runtime_error("File not found: " + path);
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
