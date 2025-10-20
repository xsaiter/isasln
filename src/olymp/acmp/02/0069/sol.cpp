#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.00001;
const double PI = 3.141592653;

bool c_eq(double a, double b) {
  return abs(a - b) < EPS;
}

bool c_less(double a, double b) {
  return a < b && !c_eq(a, b);
}

bool solve(double n, double a) {
  double fi = (2.0 * PI) / (2.0 * n);
  double x = 1.0 / cos(fi) - tan(fi);
  double d = (a / 2.0) * x;
  return c_less(d, 1.0);
}

int main() {
  double n, a;
  cin >> n >> a;
  cout << (solve(n, a) ? "YES" : "NO") << endl;
  return 0;
}