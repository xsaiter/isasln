#include <bits/stdc++.h>

using namespace std;

const double INF = 1e9;
const double EPS = 0.01;

struct P {
  int x, y, r;  
};

bool operator==(const P &a, const P &b) {    
  return a.x == b.x && a.y == b.y && a.r == b.r;
}  

bool operator!=(const P &a, const P &b) {
  return !(a == b);
}

double dist(const P &a, const P &b) {
  assert(a != b);
  double c = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));  
  return max(0.0, (double)(c - a.r - b.r));
}

double solve(int k, int t, vector<P> &a) {  
  double dd = INF;
  for (int i = 0; i < k - 1; ++i) {
    for (int j = i + 1; j < k; ++j) {
       double d = dist(a[i], a[j]);       
       if (d - 0.0 <= EPS) {
         return 0.0;
       }
       dd = min(dd, d);
    }
  }  
  double ans = t;
  if (dd < 2.0 * ans) {
    ans = dd / 2.0;
  }
  return ans;
}

int main() {
  int k, t;
  cin >> k >> t;
  vector<P> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].r;
  }
  double ans = solve(k, t, a);
  printf("%.2f", ans);
  return 0;
}