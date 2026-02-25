#include <string>
#include "commit.hpp"

void cmd_commit(const std::string& message) {
    commit(message);
}
