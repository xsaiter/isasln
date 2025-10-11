#include <bits/stdc++.h>

using namespace std;

const double MINS_PER_HOUR = 60.0;

struct E {
  int x, t;
  double t_hour() const {
    return t / MINS_PER_HOUR;
  }
};

double to_min(double hours) {
  return hours * MINS_PER_HOUR;
}

double calc_t(int d, int v) {
  return static_cast<double>(d) / v;
}

int main() {
  int n, v, l;
  cin >> n >> v >> l;
  vector<E> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].t;
  }
  double ans = 0;
  int cx = 0;
  for (int i = 0; i < n; ++i) {
    int d = a[i].x - cx;
    ans += calc_t(d, v);
    ans += a[i].t_hour();
    cx = a[i].x;
  }
  ans += calc_t(l - cx, v);
  ans = to_min(ans);
  printf("%.2f", ans);
  return 0;
}