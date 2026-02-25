#include <string>
#include <iostream>
#include "index.hpp"
#include "utils.hpp"
#include "object.hpp"

void cmd_add(const std::string& path) {
    std::string data = read_file(path);

    std::string hash = hash_object(data);

    write_object(hash, data);

    update_index(path, hash);

    std::cout << "Staged " << path << "\n";
}
