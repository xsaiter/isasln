#include <bits/stdc++.h>

using namespace std;

struct R {
  int d;
  double s;
};

struct P {
  double x, y;
};

double diag(double len) {
  return len * sqrt(2.0) / 2.0;
}

P solve(int n, vector<R> &a) {
  P r;
  r.x = 0; r.y = 0;
  for (int i = 0; i < n; ++i) {
    int d = a[i].d;
    if (d == 1) {      
      r.y += a[i].s;
    } else if (d == 2) {
      r.x += diag(a[i].s);
      r.y += diag(a[i].s);
    } else if (d == 3) {
      r.x += a[i].s;
    } else if (d == 4) {
      r.x += diag(a[i].s);
      r.y -= diag(a[i].s);
    } else if (d == 5) {
      r.y -= a[i].s;
    } else if (d == 6) {
      r.x -= diag(a[i].s);
      r.y -= diag(a[i].s);
    } else if (d == 7) {
      r.x -= a[i].s;
    } else if (d == 8) {
      r.x -= diag(a[i].s);
      r.y += diag(a[i].s);
    }
  }
  return r;
}

int main() {
  int n;
  cin >> n;
  vector<R> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].d >> a[i].s;
  }
  P p = solve(n, a);
  printf("%.3lf %.3lf", p.x, p.y);
  return 0;
}