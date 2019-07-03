#pragma once

#include <set>
#include <string>

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

#include "../core.hh"
#include "isa/ranges.hh"

namespace pso::msh::t_05 {
namespace details {
struct Divs {
  int x, y;
};

int operator<(const Divs &a, const Divs &b);
bool operator==(const Divs &a, const Divs &b);
bool operator!=(const Divs &a, const Divs &b);
int operator<(const Divs &a, const Divs &b) {
  if (a == b) {
    return 0;
  }
  if (a.x < b.x) {
    return -1;
  }
  if (a.x > b.x) {
    return 1;
  }
  if (a.y > b.y) {
    return -1;
  }
  if (a.y < b.y) {
    return 1;
  }
  return 0;
}

bool operator==(const Divs &a, const Divs &b) {
  return (a.x == b.x && a.y == b.y) || (a.x == b.y && a.y == b.x);
}
bool operator!=(const Divs &a, const Divs &b) { return !(a == b); }
} // namespace details

struct A_friendly {
  std::set<details::Divs> run(int m, int n) {
    std::set<details::Divs> res;
    for (int i = m; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (is_friendly(i, j)) {
          res.insert(details::Divs{i, j});
        }
      }
    }
    return res;
  }

private:
  bool is_friendly(int m, int n) {
    const auto divs_m = get_divisors(m);
    const auto sum_m = std::accumulate(divs_m.begin(), divs_m.end(), 0);
    const auto divs_n = get_divisors(n);
    const auto sum_n = std::accumulate(divs_n.begin(), divs_n.end(), 0);
    return m == sum_n && n == sum_m;
  }

  std::vector<int> get_divisors(int n) {
    std::vector<int> res;
    for (int i = 1; i < n; ++i) {
      if (n % i == 0) {
        res.push_back(i);
      }
    }
    return res;
  }
};

struct B_bracket2 {
  std::vector<std::string> run(int n) {
    std::vector<std::string> res;
    return res;
  }
};

struct F_birthday {
  int run(int birth_day, int birth_month, int cur_day, int cur_month,
          int cur_year) {
    if (birth_month == cur_month && birth_day == cur_day) {
      return 0;
    }
    if (birth_month == 2 && birth_day == 29) {
      return days_29_02(cur_day, cur_month, cur_year);
    }
    int days = 0;
    // after
    if (birth_month < cur_month ||
        (birth_month == cur_month && birth_day < cur_day)) {
      days = days_in_month(cur_month, cur_year) - cur_day;

      for (int i = cur_month + 1; i <= 12; ++i) {
        days += days_in_month(i, cur_year);
      }

      for (int i = 1; i < birth_month; ++i) {
        days += days_in_month(i, cur_year + 1);
      }

      days += birth_day;
    } else { // before
      if (birth_month == cur_month) {
        days = birth_day - cur_day;
      } else {
        days = days_in_month(cur_month, cur_year) - cur_day;

        for (int i = cur_month + 1; i < birth_month; ++i) {
          days += days_in_month(i, cur_year);
        }

        days += birth_day;
      }
    }
    return days;
  }

private:
  int days_in_month(int month, int year) {
    int dim[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
      return dim[month] + 1;
    }
    return dim[month];
  }

  int days_29_02(int cur_day, int cur_month, int cur_year) {
    int days = 0;
    if (is_leap_year(cur_year)) {
      if (cur_month == 2) {
        return 29 - cur_day;
      }
      if (cur_month < 2) {
        days = days_in_month(cur_month, cur_year) - cur_day;
        days += 29;
        return days;
      }
    }
    int year = cur_year;
    days = days_in_month(cur_month, year) - cur_day;
    for (int i = cur_month + 1; i <= 12; ++i) {
      days += days_in_month(i, year);
    }
    ++year;
    while (!is_leap_year(year)) {
      for (int i = 1; i <= 12; ++i) {
        days += days_in_month(i, year);
      }
      ++year;
    }
    for (int i = 1; i <= 2; ++i) {
      days += days_in_month(i, year);
    }
    return days;
  }
};

/*
 * scale
 */

struct Mod {
  std::string div;
  int rem; // remainder
};

inline static int to_int(const std::string &s) { return std::atoi(s.c_str()); }

inline static std::string to_str(int val) { return std::to_string(val); }

/*
 * a/b
 */
Mod div10(const std::string &a, int b) {
  Mod res;

  const std::size_t n = a.size();

  std::size_t i = 0;

  int rem, div;

  std::string srem;

  while (i < n) {
    std::string sub;

    int j = 0;

    while (i < n) {
      sub = a.substr(i, 1);
      srem += sub;
      ++i;
      ++j;
      if (j > 1) {
        res.div += "0";
      }
      rem = to_int(srem);
      if (rem > b) {
        break;
      }
    }

    auto new_rem = rem % b;
    div = (rem - new_rem) / b;

    srem = to_str(new_rem);
    rem = new_rem;

    res.div += to_str(div);
  }

  res.rem = rem;

  bool state = false;

  std::string x;

  for (std::size_t i = 0; i < res.div.size(); ++i) {
    if (state) {
      x += res.div[i];
    } else {
      if (res.div[i] == '0') {
      } else {
        state = true;
        x += res.div[i];
      }
    }
  }

  res.div = x;

  return res;
}

struct E_scale {
  std::string run(const std::string &val, int val_sys, int sys) {
    std::string s = to_10_from(val, val_sys);
    return from_10_to(s, sys);
  }

private:
  std::string from_10_to(const std::string &val, int sys) {
    std::string res;
    std::string s = val;
    while (true) {
      Mod m = div10(s, sys);
      res += to_char_sys(m.rem);
      s = m.div;
      const std::size_t len = s.size();
      if (len < 3) {
        int k = to_int(s);
        if (k < sys) {
          res += to_char_sys(k);
          break;
        }
      }
    }
    std::reverse(res.begin(), res.end());
    return res;
  }

  std::string to_10_from(const std::string &s, int sys) {
    std::string res;
    const std::size_t n = s.size();
    int t = 0;
    for (std::size_t i = 0; i < n; ++i) {
      int v = from_char_sys(s[i]);
      t += v * std::pow(sys, n - i - 1);
    }
    res = to_str(t);
    return res;
  }

  char to_char_sys(int v) {
    if (v < 10) {
      int c0 = '0';
      c0 += v;
      return static_cast<char>(c0);
    }
    int a = 'A';
    a += v;
    a -= 10;
    return static_cast<char>(a);
  }

  int from_char_sys(char c) {
    int v = static_cast<int>(c);

    int c0 = '0';
    if (c >= '0' && c <= '9') {
      v -= c0;
      return v;
    }
    int a = 'A';
    v -= a;
    v += 10;
    return v;
  }
};
} // namespace pso::msh::t_05
