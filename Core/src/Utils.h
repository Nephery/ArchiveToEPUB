#pragma once

#include <string>
#include <vector>

std::vector<std::string> strsplit(const std::string &s, char delim);
std::vector<std::string> strsplit(const std::string &s, char delim, bool first_occur);