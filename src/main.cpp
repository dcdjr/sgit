#include <iostream>
#include <string>
#include "init.hpp"
#include "add.hpp"
#include "commit.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: sgit <command>\n";
        return 1;
    }

    std::string cmd = argv[1];

    if (cmd == "init") {
        cmd_init();
    } else if (cmd == "add") {
        if (argc < 3) {
            std::cerr << "Usage: sgit add <file>\n";
            return 1;
        }
        cmd_add(argv[2]);
    } else if (cmd == "commit") {
        if (argc < 3) {
            std::cerr << "Usage: sgit commit <message>\n";
            return 1;
        }
        cmd_commit(argv[2]);
    } else {
        std::cerr << "Unknown command\n";
    }

    return 0;
}
