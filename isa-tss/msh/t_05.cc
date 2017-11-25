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

bool is_leap_year(int year) {
  return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int t_05_birthday(int day, int month, int cur_day, int cur_month,
                  int cur_year) {}
}
}
