#include <bits/stdc++.h>

using namespace std;

using L = long long;

struct Res {
  bool yes;
  L v;
};

Res solve(L n, L v, L k) {
  Res res { .yes = true, .v = 0 };
  L V = n * v;  
  for (L i = 1; i <= n - 1; ++i) {
    L rem = v - k * i;
    if (rem <= 0) {
      res.yes = false;
      rem = 0;
    }
    V -= rem;
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