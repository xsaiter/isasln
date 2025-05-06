#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(L a1, L a2, L n) {
  if (n == 1) {
    return a1;
  }
  if (n == 2) {
    return a2;
  }
  L d = a2 - a1;
  return d * (n - 2) + a2;
}

int main() {
  L a1, a2, n;
  cin >> a1 >> a2 >> n;
  cout << solve(a1, a2, n) << endl;
  return 0;
}