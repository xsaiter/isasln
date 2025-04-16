#include <bits/stdc++.h>

using namespace std;

using L = long long;

struct P {
  L x, y;
};

L dist(const P&a, const P &b) {
  return (a.x - b.x) * (a.x - b.x) + 
    (a.y - b.y) * (a.y - b.y);
}

bool solve(int n, const vector<P> &c, const P &a, const P &b) {
  L d = dist(a, b);
  for (int i = 0; i < n; ++i) {     
    L d2 = dist(c[i], b);
    if (d2 <= d) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<P> c(n);
    for (int i = 0; i < n; ++i) {
      cin >> c[i].x >> c[i].y;
    }
    P a;
    cin >> a.x >> a.y;
    P b;
    cin >> b.x >> b.y;
    cout << (solve(n, c, a, b) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}