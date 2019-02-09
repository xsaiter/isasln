#pragma once

#include <vector>
#include <string>
#include "geo/geo.hh"
#include <lia/matrix.hh>

namespace msh {
std::vector<int> t_02_a_primes2(int m, int n);

std::vector<std::string> t_02_b_permut(const std::string &s);

isa::lia::matrix_s<char> t_02_c_route(isa::lia::matrix_s<int> &nums);

bool t_02_d_segments(const isa::geo::segment_s<int> &s1,
                     const isa::geo::segment_s<int> &s2);

void t_02_f_spiral(int n);
}
