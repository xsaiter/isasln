#include <bits/stdc++.h>

using namespace std;

using L = long long;

struct Res {
  bool yes;
  L v;
};

Res solve(L n, L v, L k) {
  Res res { .yes = true, .v = 0 };
  L V = 0;  
  for (L i = 0; i < n; ++i) {
    L m = v - k * i;
    if (m <= 0) {
      res.yes = false;
      m = 0;
    }
    V += m;
  }
  res.v = V;  
  return res;
}

int main() {
  L n, v, k;
  cin >> n >> v >> k;
  Res r = solve(n, v, k);
  cout << (r.yes ? "YES" : "NO") << ' ' << r.v << endl;
  return 0;
}