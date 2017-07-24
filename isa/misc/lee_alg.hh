#pragma once

#include <vector>

namespace isa {
namespace misc {

struct lee_cell_t {
  int n;
  int x, y;
  bool discovered;
  bool visited;
};

struct lee_opts_t {
  int **a;
  int rows, cols;
  int beg_x, beg_y;
  int end_x, end_y;
};

bool lee_alg(const lee_opts_t &opts, std::vector<lee_cell_t> &result);
}
}
