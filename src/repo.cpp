#include <iostream>
#include <filesystem>
#include <fstream>

void init_repo() {
    std::filesystem::create_directory(".sgit");
    std::filesystem::create_directory(".sgit/objects");
    std::filesystem::create_directory(".sgit/refs");

    std::ofstream head(".sgit/HEAD");
    head << "ref: refs/main\n";
}
