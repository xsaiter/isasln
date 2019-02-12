#pragma once

#include <algorithm>
#include <cassert>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "core.hh"
#include "geo/geo.hh"

#include "numeric.hh"

namespace pso::msh::t_01 {
////////////////
void a_primes(int m, int n, std::vector<int> &res) {
  assert(m <= n);

  for (int i = m; i <= n; ++i) {
    if (isa::is_prime(i)) {
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
}

////////////////
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

////////////////
void c_incseq(const std::vector<int> &a, std::vector<int> &res) {}

////////////////
bool d_tria_pt(const isa::geo::point_s<int> &a, const isa::geo::point_s<int> &b,
               const isa::geo::point_s<int> &c,
               const isa::geo::point_s<int> &p) {
  auto x1 = isa::geo::cross_product(a, b, p);
  auto x2 = isa::geo::cross_product(b, c, p);
  auto x3 = isa::geo::cross_product(c, a, p);
  return (x1 > 0 && x2 > 0 && x3 > 0) || (x1 < 0 && x2 < 0 && x3 < 0);
}

////////////////
std::string f_poker(int x1, int x2, int x3, int x4, int x5) {
  std::string res;
  std::set<int> v{x1, x2, x3, x4, x5};
  auto n = v.size();
  if (n == 1) {
    res.assign("impossible");
  }
  if (n == 2) {
    return "four of a kind";
  }

  return "nothing";
}
}
