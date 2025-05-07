#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(L n, L a, L b) {
  return 2L * n * a * b;
}

int main() {
  L n, a, b;
  cin >> n >> a >> b;
  cout << solve(n, a, b) << endl;
  return 0;
}