#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1415926;
const double EPS = 0.001;

struct P {
  int x, y;
};

bool eq(double a, double b) {
  return abs(a - b) <= EPS;
}

double area(int r) {
  return PI * pow((double)r, 2);
}

double dist(P &a, P &b) {
  return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
}

bool solve(P &c1, P &c2, int r, int s) {
  double d = dist(c1, c2);
  if (dist <= 2 * r) {
    return 2 * area(r) > s;
  }
  return false;
}

int main() {
  P c1, c2;
  cin >> c1.x >> x1.y;
  cin >> c2.x >> x2.y;
  int r;
  cin >> r;
  int s;
  cin >> s;
  cout << (solve(c1, c2, r, s) ? "YES" : "NO");
  return 0;
}