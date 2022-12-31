#include <bits/stdc++.h>

using namespace std;

using L = long long;

struct Res {
  L mi, ma;
};

Res solve(vector<int> &a, int n, int x) {
  Res res;
  L mi = 0, ma = 0;  
  for (int i = 0; i < n; ++i) {
    ma += a[i];
  }
  ma = calc(ma, x);
  for (int i = 0; i < n; ++i) {
    L tmp = ma + x;
    if (tmp % x == 0) {
      mi += tmp;
    }
  }
  res.mi = mi;
  res.ma = ma;
  return res; 
}

L calc(L t, L x) {
  double res = t / x + 0.5;
  return (L)res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    Res res = solve(a, n, x);
  }
  return 0;
}