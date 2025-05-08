#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1415926;
const double EPS = 0.001;

struct P {
  double x, y;
};

bool c_eq(double a, double b) {
  return abs(a - b) <= EPS;
}

bool c_less(double a, double b) {
  return a < b && !c_eq(a, b);
}

bool c_less_eq(double a, double b) {
  return c_eq(a, b) || c_less(a, b);
}

double area(double r) {
  return PI * pow(r, 2);
}

double dist(const P &a, const P &b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double area_inter(double d, double r) {
  return 2 * pow(r, 2) * acos(d / (2 * r)) - (d / 2) * sqrt(4 * pow(r, 2) - pow(d, 2));
}

bool solve(const P &c1, const P &c2, double r, double s) {
  double a = area(r);
  double d = dist(c1, c2);  
  if (c_eq(d, 0.0)) {
    return c_less(s, a);
  }
  if (c_less_eq(2.0 * r, d)) {
    return c_less(s, 2 * a);
  }  
  double aa = 2 * a - area_inter(d, r);
  return c_less(s, aa);  
}

int main() {
  P c1, c2;
  cin >> c1.x >> c1.y;
  cin >> c2.x >> c2.y;
  double r;
  cin >> r;
  double s;
  cin >> s;
  cout << (solve(c1, c2, r, s) ? "YES" : "NO");
  return 0;
}