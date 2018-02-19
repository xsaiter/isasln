#pragma once

#include <string>
#include <vector>
#include <tuple>

#include "lia/matrix.hh"

namespace iom {
struct max_mult_res_s {
  int x1, x2, x3;
  max_mult_res_s(int x1_, int x2_, int x3_) : x1(x1_), x2(x2_), x3(x3_) {}
};
max_mult_res_s iom_03_a_max_mult(const std::vector<int> &v);

isa::lia::matrix_s<int> iom_03_square(int n, int k, int s);
}
