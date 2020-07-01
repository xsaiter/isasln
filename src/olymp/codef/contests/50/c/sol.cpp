#include <bits/stdc++.h>

using namespace std;

struct P { int x, y; };

int orient(P p, P q, P r) { 
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);   
  if (val == 0) return 0;
  return (val > 0) ? 1 : 2;
} 

int dist2(const P &a, const P &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return dx * dx + dy * dy;
}

P next_top(stack<P> &h) { 
  P p = h.top(); h.pop(); 
  P res = h.top(); 
  h.push(p); 
  return res; 
} 

stack<P> get_hull(vector<P> &points, int n) {  
  stack<P> res;
  if (n < 4) {
    for (auto &p : points) res.push(p);
    return res;
  }
  int min_y_pos = 0;
  int min_y = points[0].y;
  for (int i = 1; i < n; ++i) {
    if (points[i].y < min_y) {
      min_y = points[i].y;
      min_y_pos = i;
    }
  }
  std::swap(points[0], points[min_y_pos]);
  auto fi = points[0];
  auto beg = begin(points);
  std::advance(beg, 1);
  std::sort(beg, points.end(), [&](const auto &a, const auto &b) {
    int cp = orient(a, b, fi);
    if (cp == 0) return dist2(fi, a) > dist2(fi, b); else return cp > 0;
  });
  res.push(points[0]); res.push(points[1]); res.push(points[2]);
  for (int i = 3; i < n; ++i) {
    while (orient(next_top(res), res.top(), points[i]) != 2) res.pop(); 
    res.push(points[i]); 
  }
  return res;
}

void debug_hull(stack<P> &h) {
  while (!h.empty()) {
    P p = h.top(); h.pop();
    cout << p.x << " " << p.y << "\n";
  }
  cout << endl;
}

int solve(vector<P> &points, int n) { 
  int res = 0;
  auto Len = [](const auto &l, const auto &r) { return max(abs(l.x - r.x), abs(l.y - r.y)); };  
  stack<P> h = get_hull(points, n);
  debug_hull(h);
  return 0;
  int m = (int)h.size();
  if (m == 1) return 4;
  if (m == 2) {
    auto a = h.top(); h.pop();
    auto b = h.top(); h.pop();
    return 4 + Len(a, b);
  }
  P fi = h.top(); h.pop();
  P prev = fi;  
  while (true) {
    P cur = h.top(); h.pop();
    res += Len(cur, prev);
    if (h.empty()) {
      res += Len(cur, fi);
      break;
    }
    prev = cur;
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
