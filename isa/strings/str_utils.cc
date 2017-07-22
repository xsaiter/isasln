#include <algorithm>
#include <locale>

#include <sstream>
#include <string.h>

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

std::vector<std::size_t> str_z_func(const std::string &s) {
  const std::size_t n = s.size();
  std::vector<std::size_t> res(n);
  res[0] = n;

  for (std::size_t i = 1; i < n; ++i) {
    std::size_t j = i;
    while (j < n && s[j] == s[j - i]) {
      ++j;
    }
    res[i] = j - i;
  }

  return res;
}

std::vector<std::size_t> str_prefix_func(const std::string &s) {
  const std::size_t n = s.size();

  std::vector<std::size_t> res(n);

  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t k = 1; k <= i; ++k) {
      std::size_t j = 0;
      while (j + k <= i && s[j] == s[j + k]) {
        ++j;
      }

      if (j + k == i + 1) {
        res[i] = j;
        break;
      }
    }
  }

  return res;
}

int str_boyer_moore(const std::string &s, const std::string &p) {
  const int m = p.size();
  const int n = s.size();
  const int SIZE = 256;

  int d[SIZE];
  std::fill_n(d, SIZE, -1);

  for (int i = m - 2; i >= 0; --i) {
    if (d[p[i]] == -1) {
      d[p[i]] = m - 1 - i;
    }
  }

  int shift = 1;
  for (int i = 0; i <= n - m; i += shift) {
    int j = m - 1;
    while (j >= 0) {
      if (s[i + j] != p[j]) {
        if (d[s[i + j]] == -1) {
          shift = m;
        } else {
          shift = d[s[i + j]];
        }
        break;
      }
      --j;
    }

    if (j == -1) {
      return i;
    }
  }

  return -1;
}

int str_kmp(const std::string &s, const std::string &p) {
  const std::size_t n = s.size();
  const std::size_t m = p.size();

  std::size_t j = 0;

  std::vector<std::size_t> pref = str_prefix_func(p);

  for (std::size_t i = 0; i < n; ++i) {
    while (j > 0 && (j >= m || p[j] != s[i])) {
      j = pref[j - 1];
    }

    if (s[i] == p[j]) {
      j++;
    }

    if (j == m) {
      return i - j + 1;
    }
  }

  return -1;
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
}
}
