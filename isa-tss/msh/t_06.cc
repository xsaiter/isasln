#include <algorithm>
#include "t_06.hh"

namespace tss {
namespace msh {
int t_06_a_cover(const std::vector<range_s> &ranges) {
  struct wrap_s {
    int v, t;
  };

  const int n = ranges.size();

  const int m = 2 * n;

  std::vector<wrap_s> ws;
  ws.reserve(m);

  for (int i = 0; i < n; ++i) {
    wrap_s w1 = {ranges[i].l, -1};
    ws.push_back(w1);

    wrap_s w2 = {ranges[i].r, 1};
    ws.push_back(w2);
  }

  std::sort(ws.begin(), ws.end(),
            [](const wrap_s &lhs, const wrap_s &rhs) { return lhs.v < rhs.v; });

  int res = 0;
  int s = 0;
  int x = ws[0].v;

  for (int i = 0; i < m; ++i) {
    s += ws[i].t;
    if (s == 0) {
      res += ws[i].v - x;
      x = ws[i].v;
    }
  }

  return res;
}
}
}
