#pragma once

#include <string>
#include <vector>
#include <geo/geo.hh>

namespace iom {
std::string iom_01_a_timer(const std::string &time,
                           const std::string &interval);

void iom_01_b_go_at_home();

isa::geo::point_u
iom_01_c_treasure(const std::vector<isa::geo::point_s<int>> &points);
}