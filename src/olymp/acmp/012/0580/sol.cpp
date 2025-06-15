#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.01;

bool solve(double a, double b, double c, double r) {
  double p = (a + b + c) / 2.0;
  double s = sqrt(p * (p - a) * (p - b) * (p - c));
  double re = s / p;
  return re >= r;
}

int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double r;
  cin >> r;
  cout << (solve(a, b, c, r) ? "YES" : "NO") << endl;
  return 0;
}