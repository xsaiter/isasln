#pragma once

#include <vector>
#include <string>

#include "ranges.hh"
#include "geo/geo.hh"

namespace msh {
int t_06_a_cover(const std::vector<isa::range_i_u> &ranges);

int t_06_b_sums(const std::vector<int> &nums);

int t_06_d_rectarea(const std::vector<isa::geo::rect_s<int>> &rects);
}
