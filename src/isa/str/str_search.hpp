#pragma once

#include <string>
#include <vector>

namespace isa::str {
std::vector<std::size_t> str_prefix_func(const std::string &s);
std::vector<std::size_t> str_z_func(const std::string &s);
int str_kmp(const std::string &s, const std::string &p);
int str_boyer_moore(const std::string &s, const std::string &p);
} // namespace isa::str
