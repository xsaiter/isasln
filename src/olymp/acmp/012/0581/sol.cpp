#include <bits/stdc++.h>

using namespace std;

struct P {
  double x, y;
  double dist2(const P &p) const {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
  }
  double dist(const P &p) const {
    return sqrt(dist2(p));
  }
};

struct C {
  P c;
  double r;

  double is_inside(const P &p) const {
    return c.dist2(p) <= r * r;
  }

  P ra() const() {    
  }

  P rb() const {
  }
};

struct L {
  P p1, p2;
  bool belongs(const P &p) const {
    double k = (p2.y - p1.y) / (p2.x - p1.x);
    double b = p1.y - k * p1.x;
    return p.y == k * p.x + b;
  }  
};

vector<int> solve(int n, const L &line, const vector<C> &cc) {
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    if (line.is_intersected(d[i])) {
      res.push_back(i + 1);
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  P p1;
  cin >> p1.x >> p1.y;
  P p2;
  cin >> p2.x >> p2.y;
  L line {.p1 = p1, .p2 = p2};
  vector<C> cc(n);
  for (int i = 0; i < n; ++i) {
    cin >> cc[i].c.x >> cc[i].c.y >> cc[i].r;
  }
  vector<int> res = solve(n, line, cc);
  int m = (int)res.size();
  cout << m << '\n';
  for (int i = 0 ; i < m; ++i) {
    cout << res[i] << ' ';
  }
  cout << endl;
  return 0;
}

