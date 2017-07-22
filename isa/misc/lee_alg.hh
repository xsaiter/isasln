#pragma once

#include <vector>

namespace isa {
namespace misc {

struct lee_cell {
  int n;
  int x, y;
  bool discovered;
  bool visited;
};

struct lee_opts {
  int **a;
  int rows, cols;
  int beg_x, beg_y;
  int end_x, end_y;
};

bool lee_alg(const lee_opts &opts, std::vector<lee_cell> &result);
}
}
