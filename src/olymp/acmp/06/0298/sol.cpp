#include <bits/stdc++.h>

using namespace std;

const double INF = (double)1e9;
const double EPS = 0.01;

struct P {
  int x, y;
  double k() {
    if (x == 0) {
      return EPS;
    }
    return (double)y / (double)x;
  }
  bool is_zero() {
    return x == 0 && y == 0;
  }
};

struct PCmp {
  bool operator() (const P& a, const P& b) const {
    if (a.x == b.x) {
      return a.y < b.y;
    }
    return a.x < b.x;
  }
};

bool is_dir(const P& a, const P& b) {
  return ((a.x > 0 && b.x > 0) || (a.x < 0 && b.x < 0) || (a.x == 0 && b.x == 0))
    && ((a.y > 0 && b.y > 0) || (a.y < 0 && b.y < 0) || (a.y == 0 && b.y == 0));
}

int solve(int n, vector<P>& a) {
  int ans = 0;
  vector<int> vis(n, 0);
  bool has_zero = false;
  for (int i = 0; i < n; ++i) {
    if (a[i].is_zero()) {
      has_zero = true;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i].is_zero()) {
      continue;
    }
    if (vis[i] == 0) {
      ans += 1;
      vis[i] = 1;
      for (int j = i + 1; j < n; ++j) {
        if (a[j].is_zero()) {
          continue;
        }
        if (vis[j] == 0 && is_dir(a[i], a[j])) {
          if (abs(a[i].k() - a[j].k()) <= EPS) {
            vis[j] = 1;
          }
        }
      }
    }
  }
  if (ans == 0) {
    if (has_zero) {
      ans += 1;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  set<P, PCmp> s(a.begin(), a.end());
  vector<P> b(s.begin(), s.end());
  n = (int)b.size();    
  cout << solve(n, b) << endl;
  return 0;
}