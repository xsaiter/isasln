#include <algorithm>

#include <vector>

#include "t_05.hh"

namespace tss {
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

int t_05_birthday(int birth_day, int birth_month, int cur_day, int cur_month,
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

std::string t_05_e_scale(int src_val, int src, int dest) {}
}
}
