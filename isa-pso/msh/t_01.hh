#pragma once

#include <string>
#include <vector>

#include "../core.hh"
#include "geo/geo.hh"

namespace msh {
void t_01_a_primes(int m, int n, std::vector<int> &res);

void t_01_b_expr(const std::vector<int> &nums, int s, std::string &res);

void t_01_c_incseq(const std::vector<int> &a, std::vector<int> &res);

bool t_01_d_tria_pt(const isa::geo::point_s<int> &a,
                    const isa::geo::point_s<int> &b,
                    const isa::geo::point_s<int> &c,
                    const isa::geo::point_s<int> &p);
}
