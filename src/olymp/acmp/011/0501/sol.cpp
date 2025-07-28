#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

struct R {
  P a, b;  
  int intersection_area(const R &r) const {    
    if (a.x <= r.a.x && r.a.x <= b.x) {
    }
  }
};

int solve(vector<R> &a, int n, R &b) {
  int res = 0;
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<R> a(n);
  for (int i = 0 ; i < n; ++i) {
    cin >> a[i].a.x >> a[i].a.y;
    cin >> a[i].b.x >> a[i].b.y;
  }
  R b;
  cin >> b.a.x >> b.a.y;
  cin >> b.b.x >> b.b.y;
  cout << solve(a, n, b);
  return 0;
}