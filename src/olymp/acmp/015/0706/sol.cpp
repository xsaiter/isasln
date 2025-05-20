#include <bits/stdc++.h>

using namespace std;

double solve(double r, double x, double y) {
  x = abs(x);
  return r * x / (2 * r - y);
}

int main() {
  double r, x, y;
  cin >> r >> x >> y;
  double d = solve(r, x, y);
  printf("%.2f", d);
  return 0;
}