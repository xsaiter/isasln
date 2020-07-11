#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

int rot(const P &a, const P &b, const P &c) {
  int r = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
  if (r == 0) {
    return 0;
  }
  return (r > 0) ? 1 : -1;
}

int dist2(const P &a, const P &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return dx * dx + dy * dy;
}

stack<P> get_hull(vector<P> &points, int n) {
  stack<P> res;
  if (n <= 3) {
    for (auto &p : points) {
      res.push(p);
    }
    return res;
  }
  auto CmpSortAll = [](const P &l, const P &r) {
    if (l.y == r.y) {
      return l.x < r.x;
    }
    return l.y < r.y;
  };
  sort(begin(points), end(points), CmpSortAll);
  auto p0 = points[0];
  auto beg = begin(points);
  std::advance(beg, 1);
  auto CmpSortRest = [&](const auto &a, const auto &b) {
    int x = rot(a, b, p0);
    if (x == 0) {
      return dist2(p0, a) > dist2(p0, b);
    } else {
      return x > 0;
    }
  };
  std::sort(beg, points.end(), CmpSortRest);
  res.push(points[0]);
  res.push(points[1]);
  res.push(points[2]);
  for (int i = 3; i < n; ++i) {
    while (!res.empty()) {
      auto top = res.top();
      res.pop();
      if (res.empty())
        break;
      auto next_top = res.top();
      res.push(top);
      auto rr = rot(next_top, top, points[i]);
      if (rr == 1)
        break;
      res.pop();
    }
    res.push(points[i]);
  }
  return res;
}

int solve(vector<P> &points, int n) {
  int res = 0;
  auto Len = [](const P &l, const P &r) {
    return max(abs(l.x - r.x), abs(l.y - r.y));
  };
  stack<P> h = get_hull(points, n);
  int m = (int)h.size();
  if (m == 2) {
    auto a = h.top();
    h.pop();
    auto b = h.top();
    h.pop();
    return 4 + Len(a, b);
  }
  P p0 = h.top();
  h.pop();
  P next_top = p0;
  while (true) {
    if (h.empty())
      break;
    P top = h.top();
    h.pop();
    res += Len(top, next_top);
    if (h.empty()) {
      res += Len(top, p0);
      break;
    }
    next_top = top;
  }
  res += 4;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<P> points(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points[i] = {x, y};
  }
  cout << solve(points, n) << endl;
  return 0;
}
