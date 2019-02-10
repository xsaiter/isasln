#pragma once

#include <string>
#include <vector>

#include "../core.hh"
#include "geo/geo.hh"

#include <cassert>
#include <sstream>

#include "numeric.hh"

namespace pso::msh::t_01 {
void a_primes(int m, int n, std::vector<int> &res) {
  assert(m <= n);

  for (int i = m; i <= n; ++i) {
    if (isa::is_prime(i)) {
      res.push_back(i);
    }
  }
}

namespace details {
int calc(const std::vector<int> &nums, int v) {
  int r = nums[0];

  const int n = nums.size();

  for (int i = 1; i < n; ++i) {
    if ((v & (1 << (i - 1))) > 0) {
      r += nums[i];
    } else {
      r += nums[i] * (-1);
    }
  }

  return r;
}
}

void b_expr(const std::vector<int> &nums, int s, std::string &res) {
  const int n = nums.size();
  const int nn = (n - 1) * (n - 1);

  int i = 0;

  while (i < nn && s != details::calc(nums, i)) {
    i++;
  }

  std::ostringstream ss;

  if (i < nn) {
    ss << nums[0];

    for (int j = 1; j < n; ++j) {
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

void c_incseq(const std::vector<int> &a, std::vector<int> &res) {}

bool d_tria_pt(const isa::geo::point_s<int> &a, const isa::geo::point_s<int> &b,
               const isa::geo::point_s<int> &c,
               const isa::geo::point_s<int> &p) {
  auto x1 = isa::geo::cross_product(a, b, p);
  auto x2 = isa::geo::cross_product(b, c, p);
  auto x3 = isa::geo::cross_product(c, a, p);

  return (x1 > 0 && x2 > 0 && x3 > 0) || (x1 < 0 && x2 < 0 && x3 < 0);
}
}
