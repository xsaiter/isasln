#include <bits/stdc++.h>

using namespace std;
using R = long long;

inline R mul(int x, int y) {
  return (R)x * (R)y;
}

R get(int a, int b, int x, int y, int n) {
  R res = 0;
  int d = a - x;
  if (d >= n) {
    a -= n;
    res = mul(a, b);
  } else {
    n -= d;
    d = b - y;
    if (d >= n) {
      res = mul(x, b - n);
    } else {
      res = mul(x, y);
    }
  }
  return res;  
}

R solve(int a, int b, int x, int y, int n) {    
  R sa = get(a, b, x, y, n);
  R sb = get(b, a, y, x, n);
  return min(sa, sb);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    cout << solve(a, b, x, y, n) << "\n";
  }
  cout << endl;
  return 0;
}