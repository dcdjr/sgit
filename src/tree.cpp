#include <string>
#include <sstream>
#include "tree.hpp"
#include "utils.hpp"
#include "object.hpp"

// Writes tree object to .sgit/objects
std::string write_tree() {
    std::string data = read_file(".sgit/index");
    std::string tree_content = "";
    std::stringstream ss(data);

    std::string line;
    std::string hash;
    std::string filename;

    while (std::getline(ss, line, '\n')) {
        if (line.empty()) continue;

        size_t space = line.find(' ');
        if (space == std::string::npos) continue;

        filename = line.substr(0, space);
        hash = line.substr(space + 1);

        tree_content += "blob " + hash + " " + filename + "\n";
    }

    std::string tree_hash = hash_object(tree_content);

    write_object(tree_hash, tree_content);

    return tree_hash;
}
