#include <bits/stdc++.h>

using namespace std;
using R = long long;

R solve(R a, R b, R c, R d) {
  if (a <= b) return b;
  if (c <= d) return -1;
  R res = 0;
  res += b;
  a -= b;
  R cd = c - d;
  R r = a % cd;
  R x = (a - r) / cd;
  res += c * x;
  if (r > 0) res += c;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    R a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d) << "\n";
  }
  cout << endl;
  return 0;
}