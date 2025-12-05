#include <bits/stdc++.h>

using namespace std;

using L = long long;

struct Res {
  int mi, ma;
};

L calc(L t, int x) {
  long double r = (long double)t / (long double)x;
  return (L)ceill(r);
}

Res solve(vector<int> &a, int n, int x) {  
  L mi = 0, ma = 0;  
  for (int i = 0; i < n; ++i) {
    ma += calc(a[i], x);
  }
  L cur = 0;  
  for (int i = 0; i < n; ++i) {
    cur += a[i];
  }
  mi += calc(cur, x);
  Res res;
  res.mi = mi;
  res.ma = ma;
  return res; 
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
    cout << res.mi << " " << res.ma << "\n";
  }
  cout << endl;
  return 0;
}