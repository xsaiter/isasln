#pragma once

#include <vector>
#include "geo/geo.hh"

namespace msh {
void t_04_a_perfect(int m, int n, std::vector<int> &res);

double t_04_d_area(const std::vector<isa::geo::point_u> &points);
}
