#include <bits/stdc++.h>

using namespace std;
using L = long long;

// k, k + 1, .., k + n - 1
// i so min of x = |a1 + a2 + .. + ai - a[i+1] - ... - a[n]|

L solve(L n, L k) {
  L res = INT_MAX;
  L s = (k + k + n - 1L) * n / 2L;
  for (L j = 1; j <= n; ++j) {
    L a = (k + k + j - 1L) * j / 2L;
    res = min(res, abs(2L * a - s));
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >>  n >> k;
    cout << solve(n, k) << '\n';
  }
  cout << endl;
  return 0;
}