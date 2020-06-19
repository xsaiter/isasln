#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

using pdd = pair<double, double>;

double area_trap(double a, double b, double h) { return 0.5 * h * (a + b); }

pdd calc_ht(double a, double s, double z) {
  double d = 4 * a * a * z * z - 4 * a * 2 * s * z;
  double sd = sqrt(d);
  return {(2 * a * z + sd) / (2 * a), (2 * a * z - sd) / (2 * a)};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(15);
  cout << fixed;
  int n, h;
  cin >> n >> h;
  double s = 0.5 * h * 1 / n;
  int m = n - 1;
  vector<double> a(m + 1);
  a[0] = 1;
  vector<double> hs(m, 0);
  for (int i = 0; i < m; ++i) {
    double x = 0;
    for (int j = 0; j < i; ++j) {
      x += hs[j];
    }
    double z = h - x;
    hs[i] = calc_ht(a[i], s, z).se;
    a[i + 1] = 2 * s / hs[i] - a[i];
  }
  vector<double> res(m);
  double cur = 0;
  for (int i = 0; i < m; ++i) {
    cur += hs[i];
    res[i] = h - cur;
  }
  for (int i = 0; i < m; ++i) {
    cout << res[m - 1 - i] << " ";
  }
  cout << endl;
  return 0;
}