#pragma once

#include "isa/geo/geo.hpp"
#include <algorithm>
#include <string>

namespace pso::msh::t_10 {
struct B_fibostr {
  int run(int n, const std::string &s) {
    std::string a("a");
    int ra = a == s ? 1 : 0;
    if (n == 0) {
      return ra;
    }
    std::string b("b");
    int rb = b == s ? 1 : 0;
    if (n == 1) {
      return rb;
    }
    std::string x;
    int rx = 0;
    for (int i = 2; i <= n; ++i) {
      x = b + a;
      int e = repeats_bound(x, b.size(), s);
      a = b;
      b = x;
      rx = rb + ra + e;
      ra = rb;
      rb = rx;
    }
    return rx;
  }

private:
  int repeats_bound(const std::string &s, std::size_t bound,
                    const std::string &p) {
    int res = 0;
    const std::size_t m = p.size();
    std::size_t beg = bound >= m ? bound - m : 0;
    for (std::size_t i = beg; i < bound; ++i) {
      std::size_t j = 0;
      while (j < m && s[i + j] == p[j]) {
        ++j;
      }
      if (j == m && i + j > bound) {
        ++res;
      }
    }
    return res;
  }
};

struct D_border {
  using Pt = isa::geo::Point<int>;
  using Pts = std::vector<Pt>;

  int run(Pts pts) {
    const auto n = pts.size();
    if (n < 3) {
      return 0;
    }
    auto s = 0;
    for (auto i = 1; i < n - 1; ++i) {
      auto p = isa::geo::cross_product(pts[0], pts[i], pts[i + 1]);
      s += p / 2;
    }
    // auto xleft = std::min(pts)
  }
};
} // namespace pso::msh::t_10
