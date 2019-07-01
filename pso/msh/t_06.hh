#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include "isa/geo/geo.hh"
#include "isa/graphs/lee_alg.hh"
#include "isa/ranges.hh"

namespace pso::msh::t_06 {
struct a_cover {
  int run(const std::vector<isa::range_i_u> &ranges) {
    struct wrap_s {
      int v, t;
    };

    const std::size_t n = ranges.size();
    const std::size_t m = 2 * n;

    std::vector<wrap_s> ws;
    ws.reserve(m);

    for (std::size_t i = 0; i < n; ++i) {
      ws.push_back({ranges[i].l, -1});
      ws.push_back({ranges[i].r, 1});
    }

    std::sort(ws.begin(), ws.end(), [](const wrap_s &lhs, const wrap_s &rhs) {
      return lhs.v < rhs.v;
    });

    int res = 0;
    int s = 0;
    int x = ws[0].v;
    bool state = false;

    for (std::size_t i = 0; i < m; ++i) {
      if (ws[i].t == -1 && !state) {
        x = ws[i].v;
        state = true;
      }
      s += ws[i].t;
      if (s == 0) {
        res += ws[i].v - x;
        state = false;
      }
    }

    return res;
  }
};

struct b_sums {
  int run(const std::vector<int> &nums) { return 0; }
};

struct d_rectarea {
  int run(const std::vector<isa::geo::rect_s<int>> &rects) { return 0; }
};

struct e_lines {
  struct route_s {
    std::vector<std::vector<char>> a;
  };

  bool run(const std::vector<std::vector<char>> &a, std::size_t n,
           route_s &res) {
    isa::graphs::lee_opts_s opts;
    opts.rows = opts.cols = n;
    opts.a.resize(n, std::vector<int>(n));

    for (std::size_t i = 0; i < n; ++i) {
      for (std::size_t j = 0; j < n; ++j) {
        char c = a[i][j];
        if (c == 'O') {
          opts.a[i][j] = 1;
        } else {
          opts.a[i][j] = 0;
          if (c == '@') {
            opts.beg_x = j;
            opts.beg_y = i;
          } else if (c == 'X') {
            opts.end_x = j;
            opts.end_y = i;
          }
        }
      }
    }

    std::vector<isa::graphs::lee_cell_s> cells;
    auto exists = isa::graphs::lee_alg(opts, cells);
    if (!exists) {
      return false;
    }

    res.a.resize(n, std::vector<char>(n));

    for (std::size_t i = 0; i < n; ++i) {
      for (std::size_t j = 0; j < n; ++j) {
        res.a[i][j] = a[i][j];
      }
    }

    for (const isa::graphs::lee_cell_s &ce : cells) {
      auto x = ce.x;
      auto y = ce.y;
      res.a[x][y] = '+';
    }

    return true;
  }
};
} // namespace pso::msh::t_06
