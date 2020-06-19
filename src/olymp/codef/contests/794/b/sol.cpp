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
  cout.precision(12);
  cout << fixed;
  int n, h;
  cin >> n >> h;
  double ss = 0.5 * h * 1;
  double s = ss / n;
  int m = n - 1;
  vector<double> a(m);
  a[0] = 1;
  vector<double> hh(m, 0);
  for (int i = 0; i < m; ++i) {
    double x = 0;
    for (int j = 0; j < i; ++j) {
      x += hh[j];
    }
    double z = h - x;
    hh[i] = calc_ht(a[i], s, z).se;
  }
  vector<double> res(m);
  double cur = 0;
  for (int i = 0; i < m; ++i) {
    cur = hh[i];
    res[i] = cur;
  }
  for (int i = 0; i < m; ++i) {
    cout << res[i] << " ";
    // printf("%.12lf ", res[i]);
  }
  cout << endl;
  return 0;
}