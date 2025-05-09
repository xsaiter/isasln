#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.001;
const double PI = 3.1415926;

bool c_eq(double a, double b) {
  return abs(a - b) < EPS;
}

bool c_less(double a, double b) {
  return a < b && !c_eq(a, b);
}

bool solve(double n, double a) {
  double fi = (2 * PI) / (2 * n);
  double x = 1 / cos(fi) - tan(fi);
  double d = (a / 2) * x;
  return c_less(d, 1);  
}

int main() {
  double n, a;
  cin >> n >> a;  
  cout << (solve(n, a) ? "YES" : "NO") << endl;
  return 0;
}