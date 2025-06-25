#include <bits/stdc++.h>

using namespace std;

const double SHIFT = 1e6;

struct P {
  double x, y;  
};

double dist(const P &a, const P &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double median(double a, double b) {
  return (a + b) / 2;
}

P center(const P &a, const P &b) {  
  double nx = median(a.x, b.x);
  double ny = median(a.y, b.y);
  
  return P { .x = nx, .y = ny };
}

double len(int n, const vector<P> &a) {
  double ans = 0;
  for (int i = 1; i < n; ++i) {    
    ans += dist(a[i], a[i - 1]);
  }
  ans += dist(a[0], a[n - 1]);
  return ans;
}

vector<P> conv(int n, const vector<P> &a) {  
  vector<P> b(n);
  for (int i = 1; i < n; ++i) {
    b[i] = center(a[i], a[i - 1]);    
  }
  b[0] = center(a[0], a[n - 1]);
  return b;
}

vector<P> dual(int n, const vector<P> &a, int k) {  
  vector<P> b = a;
  for (int i = 1; i <= k; ++i) {
    b = conv(n, b);
  }
  return b;  
}

double solve(int n, const vector<P> &a, int k) {
  vector<P> b = dual(n, a, k);
  return len(n, b);
}

int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    a[i].x += SHIFT;
    a[i].y += SHIFT;
  }
  int k;
  cin >> k;
  double ans = solve(n, a, k);
  printf("%.10f", ans);
  return 0;
}