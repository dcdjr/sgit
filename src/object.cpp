#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "object.hpp"

// Takes in data (usually file contents) and returns a hash
std::string hash_object(const std::string& data) {
    size_t h = std::hash<std::string>{}(data);

    std::ostringstream oss;
    oss << std::hex << h;
    return oss.str();
}

// Writes an object to .sgit/objects
void write_object(const std::string& hash, const std::string& data) {
    std::filesystem::create_directories(".sgit/objects");

    std::string path = ".sgit/objects/" + hash;

    // If already exists, don't rewrite
    if (std::filesystem::exists(path)) {
        return;
    }

    std::ofstream out(path, std::ios::binary);
    out << data;
}
