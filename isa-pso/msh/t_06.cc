#include <algorithm>

#include "t_06.hh"

namespace msh {
int t_06_a_cover(const std::vector<isa::range_i_u> &ranges) {
  struct wrap_s {
    int v, t;
  };

  const int n = ranges.size();
  const int m = 2 * n;

  std::vector<wrap_s> ws;
  ws.reserve(m);

  for (int i = 0; i < n; ++i) {
    ws.push_back({ranges[i].l, -1});
    ws.push_back({ranges[i].r, 1});
  }

  std::sort(ws.begin(), ws.end(),
            [](const wrap_s &lhs, const wrap_s &rhs) { return lhs.v < rhs.v; });

  int res = 0;
  int s = 0;
  int x = ws[0].v;
  bool state = false;

  for (int i = 0; i < m; ++i) {
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

int t_06_b_sums(const std::vector<int> &nums) { return 0; }

int t_06_d_rectarea(const std::vector<isa::geo::rect_s<int>> &rects) {
  return isa::geo::area_union_of_rects(rects);
}
}
