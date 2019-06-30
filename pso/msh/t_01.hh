#pragma once

#include <algorithm>
#include <cassert>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "isa/geo/geo.hh"
#include "pso/core.hh"

#include "isa/ar/ar.hh"

namespace pso::msh::t_01 {
//-----------------------------
void a_primes(int m, int n, std::vector<int> &res) {
  assert(m <= n);
  for (int i = m; i <= n; ++i) {
    if (isa::ar::is_prime(i)) {
      res.push_back(i);
    }
  }
}

namespace details {
int calc(const std::vector<int> &nums, std::size_t v) {
  int r = nums[0];
  const std::size_t n = nums.size();
  for (std::size_t i = 1; i < n; ++i) {
    if ((v & (1 << (i - 1))) > 0) {
      r += nums[i];
    } else {
      r += nums[i] * (-1);
    }
  }
  return r;
}
} // namespace details

//-----------------------------
void b_expr(const std::vector<int> &nums, int s, std::string &res) {
  const std::size_t n = nums.size();
  const std::size_t nn = (n - 1) * (n - 1);

  std::size_t i = 0;

  while (i < nn && s != details::calc(nums, i)) {
    i++;
  }

  std::ostringstream ss;

  if (i < nn) {
    ss << nums[0];

    for (std::size_t j = 1; j < n; ++j) {
      if ((i & (1 << (j - 1))) > 0) {
        ss << '+';
      } else {
        ss << '-';
      }
      ss << nums[j];
    }
  }

  res.assign(ss.str());
}

//-----------------------------
std::vector<int> c_incseq(const std::vector<int> &a) {
  std::vector<int> res;
  return res;
}

//-----------------------------
bool d_tria_pt(const isa::geo::point_s<int> &a, const isa::geo::point_s<int> &b,
               const isa::geo::point_s<int> &c,
               const isa::geo::point_s<int> &p) {
  auto x1 = isa::geo::cross_product(a, b, p);
  auto x2 = isa::geo::cross_product(b, c, p);
  auto x3 = isa::geo::cross_product(c, a, p);
  return (x1 > 0 && x2 > 0 && x3 > 0) || (x1 < 0 && x2 < 0 && x3 < 0);
}

//-----------------------------
std::string e_power(int a, int n) {
  assert(1 <= a && a <= 9);
  assert(1 <= n && n <= 7000);
  std::vector<int> v(n, 0);
  v[0] = 1;
  auto len = 1;
  for (int i = 0; i < n; ++i) {
    int q = 0;
    for (int j = 0; j < len; ++j) {
      auto t = v[j] * a + q;
      auto rem = t % 10;
      v[j] = rem;
      q = (t - rem) / 10;
    }
    if (q > 0) {
      v[len] = q;
      len++;
    }
  }
  std::string s;
  s.reserve(len);
  for (auto i = len - 1; i >= 0; --i) {
    s.append(std::to_string(v[i]));
  }
  return s;
}

//-----------------------------
std::string f_poker(int x1, int x2, int x3, int x4, int x5) {
  constexpr unsigned int n = 14;
  int a[n]{0};
  ++a[x1];
  ++a[x2];
  ++a[x3];
  ++a[x4];
  ++a[x5];
  int f23 = 0;
  int f2 = 0;
  int chain = 0;
  for (unsigned int i = 0; i < n; ++i) {
    if (a[i] == 5) {
      return "impossible";
    }
    if (a[i] == 4) {
      return "four of a kind";
    }
    if (a[i] == 2) {
      if (f23 == 3) {
        f23 = -1;
      } else {
        f23 = 2;
      }
      f2++;
    } else if (a[i] == 3) {
      if (f23 == 2) {
        f23 = -1;
      } else {
        f23 = 3;
      }
    }
    if (f23 == -1) {
      return "full house";
    }
    if (a[i] == 0) {
      chain = 0;
    } else {
      ++chain;
      if (chain == 5) {
        return "straight";
      }
    }
  }
  if (f23 == 3) {
    return "three of kind";
  }
  if (f2 == 1) {
    return "one pair";
  }
  if (f2 == 2) {
    return "two pairs";
  }
  return "nothing";
}
} // namespace pso::msh::t_01
