#include <algorithm>

#include <vector>

#include "t_05.hh"

namespace msh {
static std::vector<int> get_divisors(int n) {
  std::vector<int> res;
  for (int i = 1; i < n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
    }
  }
  return res;
}

int operator<(const divs_s &a, const divs_s &b) {
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

bool operator==(const divs_s &a, const divs_s &b) {
  return (a.x == b.x && a.y == b.y) || (a.x == b.y && a.y == b.x);
}

bool operator!=(const divs_s &a, const divs_s &b) { return !(a == b); }

bool is_friendly(int m, int n) {
  const auto divs_m = get_divisors(m);
  const auto sum_m = std::accumulate(divs_m.begin(), divs_m.end(), 0);

  const auto divs_n = get_divisors(n);
  const auto sum_n = std::accumulate(divs_n.begin(), divs_n.end(), 0);

  return m == sum_n && n == sum_m;
}

std::set<divs_s> t_05_a_friendly(int m, int n) {
  std::set<divs_s> res;

  for (int i = m; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (is_friendly(i, j)) {
        res.insert(divs_s{i, j});
      }
    }
  }

  return res;
}

std::vector<std::string> t_05_b_bracket2(int n) {
  std::vector<std::string> res;

  return res;
}

inline static bool is_leap_year(int year) {
  return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

static int days_in_month(int month, int year) {
  // days in each month
  int dim[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && is_leap_year(year)) {
    return dim[month] + 1;
  }
  return dim[month];
}

static int days_29_02(int cur_day, int cur_month, int cur_year) {
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

int t_05_f_birthday(int birth_day, int birth_month, int cur_day, int cur_month,
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
      birth_month == cur_month && birth_day < cur_day) {
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

/*
 * scale
*/

struct mod_s {
  std::string div;
  int rem; // remainder
};

inline static int to_int(const std::string &s) { return std::atoi(s.c_str()); }

inline static std::string to_str(int val) { return std::to_string(val); }

/*
 * a/b
*/
mod_s div10(const std::string &a, int b) {
  mod_s res;

  const int n = a.size();

  int i = 0;

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

std::string from_10_to(const std::string &val, int sys) {
  std::string res;

  std::string s = val;

  while (true) {
    mod_s m = div10(s, sys);

    res += to_char_sys(m.rem);
    s = m.div;

    int len = s.size();
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

  const int n = s.size();

  int t = 0;

  for (int i = 0; i < n; ++i) {
    int v = from_char_sys(s[i]);
    t += v * std::pow(sys, n - i - 1);
  }

  res = to_str(t);

  return res;
}

std::string t_05_e_scale(const std::string &val, int val_sys, int sys) {
  std::string s = to_10_from(val, val_sys);
  return from_10_to(s, sys);
}
}
