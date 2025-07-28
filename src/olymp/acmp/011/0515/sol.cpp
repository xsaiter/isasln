#include <bits/stdc++.h>

using namespace std;

struct P {
  double x, y;
  double dist(P &p) const {
    return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
  }
};

double solve(int n, vector<P> &a) {
  double res = 0;
  P s {.x = 0, .y = 0};
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      res += a[i].dist(s);
    } else {
      res += a[i].dist(a[i - 1]);
    }
  }
  res += a[n - 1].dist(s);
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  double res = solve(n, a);
  printf("%.3f", res);
  return 0;
}