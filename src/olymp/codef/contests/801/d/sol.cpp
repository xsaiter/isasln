#include <bits/stdc++.h>

using namespace std;

struct P {
  double x, y;
};

double cross_prod(const P &p1, const P &p2, const P &p3) {
  return abs((p3.x - p1.x) * (p2.y - p1.y) - (p3.y - p1.y) * (p2.x - p1.x));
}

double dist(const P &p1, const P &p2) {
  double dx = (p2.x - p1.x);
  double dy = (p2.y - p1.y);
  return sqrt(dx * dx + dy * dy);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  int n;
  cin >> n;
  vector<P> pp(n);
  for (int i = 0; i < n; ++i) {
    cin >> pp[i].x >> pp[i].y;    
  }
  double res = numeric_limits<double>::max();
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    int k = (i + 2) % n;
    double r = 0.5 * cross_prod(pp[i], pp[j], pp[k]) / dist(pp[i], pp[k]);
    res = min(res, r);
  }
  cout << res << endl;
  return 0;
}