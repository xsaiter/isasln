#pragma once

#include <cmath>
#include <string>

#include "isa/geo/geo.hpp"

namespace pso::msh::t_11 {
struct D_circarea {
  double run(const isa::geo::Circle<double> &c1,
             const isa::geo::Circle<double> &c2) {
    const auto r = c1.r + c2.r;
    const auto l =
        std::sqrt(std::pow(c2.x - c1.x, 2) + std::pow(c2.y - c2.y, 2));

    if (l >= r) {
      return 0;
    }

    const auto pr1 = c1.r * c1.r;
    const auto pr2 = c2.r * c2.r;

    const auto cosa1 = (pr1 + l * l - pr2) / (2 * c1.r * l);
    const auto cosa2 = (pr2 + l * l - pr1) / (2 * c2.r * l);

    const auto a1 = std::acos(cosa1);
    const auto a2 = std::acos(cosa2);

    const auto st1 = pr1 * a1;
    const auto st2 = pr2 * a2;

    const auto s1 = c1.r * c1.r * std::sin(a1) * cosa1;
    const auto s2 = c2.r * c2.r * std::sin(a2) * cosa2;

    return st1 + st2 - s1 - s2;
  }
};
} // namespace pso::msh::t_11
