#include <bits/stdc++.h>

using namespace std;

struct P {
  int r, c;
  bool operator<(const P& p) {
    if (r == p.r) {
      return c < p.c;
    }
    return r < p.r;
  }
};

int dist(const P &a, const P &b) {
  return min(abs(a.r - b.r), abs(a.c - b.c));
}

int solve(int n, P &k, P &d) {  
  int di = dist(k, d);
  return di;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    P k, d;
    cin >> k.r >> k.c;
    cin >> d.r >> d.c;
    cout << solve(n, k, d) << '\n';
  }
  cout << endl;
  return 0;
}