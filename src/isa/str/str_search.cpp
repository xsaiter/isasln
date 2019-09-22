#include "str_search.hpp"

namespace isa::str {
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
} // namespace isa::str
