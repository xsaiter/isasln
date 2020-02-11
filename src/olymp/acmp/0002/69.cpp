#include <bits/stdc++.h>

using namespace std;

constexpr double eps = 1e-3;

int main() {
  int n, a;
  cin >> n >> a;
  double fi = (2.0 * 3.14159265358979323846) / (2.0 * (double)n);
  double x = (1 / cos(fi) - tan(fi));
  double res = ((double)a / 2.0) * x;
  bool cmp = islessequal(res, 1.0);
  if (cmp) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}