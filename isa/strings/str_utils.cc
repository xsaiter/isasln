#include <algorithm>
#include <locale>
#include <sstream>
#include <regex>

#include "str_utils.hh"

namespace isa {
namespace strings {

void str_remove_spaces(std::string &s) {
  s.erase(std::remove_if(s.begin(), s.end(), [](char x) { return isspace(x); }),
          s.end());
}

void str_to_upper(std::basic_string<char> &s) {
  std::locale loc;
  for (std::basic_string<char>::iterator p = s.begin(); p != s.end(); ++p) {
    *p = std::toupper(*p, loc);
  }
}

std::vector<std::string> str_split(const std::string &s, char delim) {
  std::stringstream ss;
  ss.str(s);

  std::vector<std::string> res;
  std::string item;
  while (std::getline(ss, item, delim)) {
    res.push_back(item);
  }

  return res;
}

bool str_is_palindrome(const std::string &s) {
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l++] != s[r--]) {
      return false;
    }
  }
  return true;
}

int str_number_of_words(const std::string &s) {
  const std::size_t len = s.size();
  int n = 0;
  std::size_t i = 0;
  unsigned spaces = 0;

  while (i < len) {
    if (isspace(s[i])) {
      if (spaces == 0) {
        ++n;
        ++spaces;
      }
    } else {
      if (i == len - 1) {
        ++n;
      } else {
        spaces = 0;
      }
    }
    ++i;
  }

  return n;
}

int str_number_of_different_letters(const std::string &s) {
  const std::size_t len = s.size();
  bool repetition = false;
  int n = 0;

  for (std::size_t i = 0; i < len; ++i) {
    for (std::size_t j = 0; j < i; ++j) {
      if (s[j] == s[i]) {
        repetition = true;
        break;
      }
    }

    if (!repetition) {
      ++n;
    } else {
      repetition = false;
    }
  }

  return n;
}

int str_levenshtein_distance(const std::string &from, const std::string &to) {
  const std::size_t n = from.size();
  const std::size_t m = to.size();

  int d[n][m];

  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < m; ++j) {
      if (i == 0 && j == 0) {
        d[i][j] = 0;
      } else if (i == 0 && j > 0) {
        d[i][j] = j;
      } else if (i > 0 && j == 0) {
        d[i][j] = i;
      } else {
        int p = d[i][j - 1] + 1;
        int q = d[i - 1][j] + 1;
        int r = d[i - 1][j - 1] + ((from[i - 1] == to[j - 1]) ? 0 : 1);
        int smallest = p;
        if (q < smallest) {
          smallest = q;
        }

        if (r < smallest) {
          smallest = r;
        }

        d[i][j] = smallest;
      }
    }
  }

  return d[n - 1][m - 1];
}

std::string
remove_words_with_consecutive_repeated_letters(const std::string &s) {
  std::regex re(R"(\s?\b\w*(\w{1})\1\w*)");
  return std::regex_replace(s, re, "");
}
}
}
