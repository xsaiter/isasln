#pragma once

#include <string>
#include <vector>

namespace isa {
namespace strings {
// prefix function
std::vector<std::size_t> str_prefix_func(const std::string &s);

// z function
std::vector<std::size_t> str_z_func(const std::string &s);

// Knuth–Morris–Pratt
int str_kmp(const std::string &s, const std::string &p);

// Boyer-Moore
int str_boyer_moore(const std::string &s, const std::string &p);
}
}
