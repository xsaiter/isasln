#pragma once

#include <vector>

namespace isa {

struct lee_cell_s {
  std::size_t n;
  std::size_t x, y;
  bool discovered;
  bool visited;
};

struct lee_opts_s {
  std::vector<std::vector<int>> a;
  std::size_t rows, cols;
  std::size_t beg_x, beg_y;
  std::size_t end_x, end_y;
};

bool lee_alg(const lee_opts_s &opts, std::vector<lee_cell_s> &result);
}
