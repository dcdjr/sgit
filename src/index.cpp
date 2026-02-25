#include <fstream>
#include <map>
#include <string>
#include "index.hpp"

void update_index(const std::string& path, const std::string& hash) {
    std::map<std::string, std::string> entries;

    // Read existing index
    std::ifstream in(".sgit/index");
    std::string file, existing_hash;
    
    
    while (in >> file >> existing_hash) {
        entries[file] = existing_hash;        
    }
    in.close();
    
    // Update or insert
    entries[path] = hash;

    // Rewrite entire index
    std::ofstream out(".sgit/index");
    for (const auto& [f, h] : entries) {
        out << f << " " << h << "\n";
    }
}
