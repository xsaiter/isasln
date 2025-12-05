#include <bits/stdc++.h>

using namespace std;
using T = long long;

struct P {
  T x, y;
};

struct P_cmp {
  bool operator()(const P &l, const P &r) const {
    if (l.x < r.x)
      return true;
    else if (l.x > r.x)
      return false;
    if (l.y < r.y)
      return true;
    return false;
  }
};

T rot(const P &a, const P &b, const P &c) {
  T r = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
  if (r == 0) {
    return 0;
  }
  return (r > 0) ? 1 : -1;
}

T dist2(const P &a, const P &b) {
  T dx = a.x - b.x;
  T dy = a.y - b.y;
  return dx * dx + dy * dy;
}

stack<P> make_hull(vector<P> &points, int n) {
  stack<P> res;
  if (n <= 3) {
    for (auto &p : points) {
      res.push(p);
    }
    return res;
  }
  auto cmp_sort_all = [](const P &l, const P &r) {
    if (l.y == r.y) {
      return l.x < r.x;
    }
    return l.y < r.y;
  };
  sort(begin(points), end(points), cmp_sort_all);
  auto p0 = points[0];
  auto beg = begin(points);
  std::advance(beg, 1);
  auto cmp_sort_rest = [&](const auto &a, const auto &b) {
    int r = rot(a, b, p0);
    if (r == 0) {
      return dist2(p0, a) < dist2(p0, b);
    }
    return r > 0;
  };
  std::sort(beg, points.end(), cmp_sort_rest);
  res.push(points[0]);
  res.push(points[1]);
  for (int i = 2; i < n; ++i) {
    while (!res.empty()) {
      auto top = res.top();
      res.pop();
      if (res.empty()) {
        res.push(top);
        break;
      }
      auto next_top = res.top();
      res.push(top);
      auto r = rot(next_top, top, points[i]);
      if (r == 1) {
        break;
      }
      res.pop();
    }
    res.push(points[i]);
  }
  return res;
}

T solve(vector<P> &points, int n) {
  T res = 0;
  auto len = [](const P &l, const P &r) {
    return max(abs(l.x - r.x), abs(l.y - r.y));
  };
  stack<P> hull = make_hull(points, n);
  int m = (int)hull.size();
  P p0 = hull.top();
  hull.pop();
  P next_top = p0;
  while (!hull.empty()) {
    P top = hull.top();
    hull.pop();
    res += len(top, next_top);
    if (hull.empty()) {
      res += len(top, p0);
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
  set<P, P_cmp> s;
  for (int i = 0; i < n; ++i) {
    T x, y;
    cin >> x >> y;
    s.insert({x, y});
  }
  vector<P> p(begin(s), end(s));
  cout << solve(p, (int)p.size()) << endl;
  return 0;
}
