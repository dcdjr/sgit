#include <string>
#include "commit.hpp"

std::string get_head_ref();
std::string get_head_commit();
void update_ref(const std::string& ref, const std::string& commit_hash);
std::string create_commit_object(
        const std::string& tree_hash,
        const std::string& parent_hash,
        const std::string& message
);
void cmd_commit(const std::string& message);
