#pragma once

#include <vector>

namespace isa {

struct lee_cell_s {
  int n;
  int x, y;
  bool discovered;
  bool visited;
};

struct lee_opts_s {
  std::vector<std::vector<int>> a;
  int rows, cols;
  int beg_x, beg_y;
  int end_x, end_y;
};

bool lee_alg(const lee_opts_s &opts, std::vector<lee_cell_s> &result);
}
