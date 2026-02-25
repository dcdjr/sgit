#pragma once
#include <string>

std::string hash_object(const std::string& data);
void write_object(const std::string& hash, const std::string& data);
