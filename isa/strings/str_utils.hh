#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace isa {
namespace strings {

void str_remove_spaces(std::string &s);
void str_to_upper(std::basic_string<char> &s);
std::vector<std::string> str_split(const std::string &s, char delim);
bool str_is_palindrome(const std::string &s);
int str_number_of_words(const std::string &s);
int str_number_of_different_letters(const std::string &s);
std::vector<std::size_t> str_prefix_func(const std::string &s);
std::vector<std::size_t> str_z_func(const std::string &s);

// Levenshtein Distance
int str_levenshtein_distance(const std::string &from, const std::string &to);

// Knuth–Morris–Pratt
int str_kmp(const std::string &s, const std::string &p);

// Boyer-Moore
int str_boyer_moore(const std::string &s, const std::string &p);
}
}
