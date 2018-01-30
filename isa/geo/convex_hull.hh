#pragma once

#include <stack>
#include <vector>

#include "geo.hh"

namespace isa {
namespace geo {
std::stack<point_s> graham_scan(std::vector<point_s> points);
}
}
