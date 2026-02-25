#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "tree.hpp"
#include "commit.hpp"
#include "utils.hpp"
#include "object.hpp"

std::string get_head_ref() {
    std::string data = read_file(".sgit/HEAD");

    std::string current_branch = data.substr(5);

    // Trim newline
    if (!current_branch.empty() && current_branch.back() == '\n')
        current_branch.pop_back();

    return current_branch;
}

std::string get_head_commit() {
    std::string current_branch = get_head_ref();

    current_branch = ".sgit/" + current_branch;
    
    try {
        std::string head_commit = read_file(current_branch);

        // Trim newline
        if (!head_commit.empty() && head_commit.back() == '\n')
            head_commit.pop_back();

        return head_commit;
    } catch (const std::runtime_error&) {
        return ""; 
    }   
}

void update_ref(const std::string& ref, const std::string& commit_hash) {
    std::ofstream out(".sgit/" + ref);
    out << commit_hash;
}

std::string create_commit_object(
        const std::string& tree_hash,
        const std::string& parent_hash,
        const std::string& message
) {
    std::string commit_object = "";
    if (parent_hash.empty()) {
        commit_object += "tree " + tree_hash + "\n" +
                         "message " + message;    
    } else {
        commit_object += "tree " + tree_hash + "\n" +
                         "parent " + parent_hash + "\n" +
                         "message " + message;
    }

    std::string commit_object_hash = hash_object(commit_object);

    write_object(commit_object_hash, commit_object);

    return commit_object_hash;
}

void commit(const std::string& message) {
    std::string tree_hash = write_tree();
    std::string parent_hash = get_head_commit();
    std::string commit_hash =
        create_commit_object(tree_hash, parent_hash, message);
    std::string ref = get_head_ref();
    update_ref(ref, commit_hash);
    
    // Truncate index
    std::ofstream(".sgit/index");

    std::cout << "Committed as " << commit_hash << "\n";
}
