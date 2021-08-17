#include <bits/stdc++.h>

using namespace std;
using L = long long;

L solve(L n, L m, L x) {
  L i = x % n;
  if (i == 0) i = n;
  L j = (x - i) / n + 1;
  return (i - 1) * m + j;  
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    L n, m, x;
    cin >> n >> m >> x;
    cout << solve(n, m, x) << '\n';
  }
  cout << endl;
  return 0;
}