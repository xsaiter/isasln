#pragma once

#include <cassert>
#include <vector>

#include "isa/ar/ar.hh"
#include "isa/geo/geo.hh"

namespace pso::msh::t_04 {
struct A_perfect {
  void run(std::size_t m, std::size_t n, std::vector<std::size_t> &res) {
    assert(m < n);
    for (std::size_t i = m; i <= n; ++i) {
      if (isa::ar::is_perfect_num(i)) {
        res.push_back(i);
      }
    }
  }
};

struct D_area {
  double run(const std::vector<isa::geo::Point<int>> &points) {
    const std::size_t n = points.size();
    if (n < 2) {
      return 0;
    }
    double res = 0.0;
    for (std::size_t i = 1; i < n - 1; ++i) {
      res += isa::geo::cross_product(points[0], points[i], points[i + 1]) / 2.0;
    }
    return std::abs(res);
  }
};
} // namespace pso::msh::t_04
