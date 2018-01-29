#pragma once

#include <stack>
#include <vector>

#include "geo.hh"

namespace isa {
namespace geo {
std::stack<point_u> graham_scan(std::vector<point_u> points);
}
}
