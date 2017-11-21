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

int str_levenshtein_distance(const std::string &from, const std::string &to);

std::string
remove_words_with_consecutive_repeated_letters(const std::string &s);

struct longest_repeated_substr_s {
  std::vector<int> all_pos;
  std::string s;
};

void find_longest_repeated_substr(const std::string &str,
                                  longest_repeated_substr_s &res);
}
}
