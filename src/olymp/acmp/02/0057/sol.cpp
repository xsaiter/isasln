#include <bits/stdc++.h>

using namespace std;

using L = long long;

const double EPS = 0.001;
const int SHIFT = 1e4;

struct P {
  int x, y;
};

double dist(const P &a, const P &b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

bool d_eq(double a, double b) {
  return abs(a - b) <= EPS;
}

bool solve(int n, int c, L p, vector<P> &a, const P &nt) {
  vector<double> dd(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
     if (i != j) {
       dd[i] += dist(a[i], a[j]);
     }
    }
  }
  double ans = DBL_MAX;
  for (int i = 0; i < n; ++i) {
    double cur = dd[i] + dist(a[i], nt);
    if (cur < ans) {
      ans = cur;
    }
  }
  double cost = ans * (double)c;
  if (cost < p || d_eq(cost, p)) {
    return true;
  }
  return false;
}

int main() {
  int n, c;
  L p;
  cin >> n >> c >> p;  
  vector<P> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    a[i].x += SHIFT; a[i].y += SHIFT;
  }
  P nt;
  cin >> nt.x >> nt.y;    
  nt.x += SHIFT; nt.y += SHIFT;
  cout << (solve(n, c, p,a,nt) ? "YES" : "NO") << endl;  
  return 0;
}