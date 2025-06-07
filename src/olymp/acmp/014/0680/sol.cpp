#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n) {
  vector<L> a(n + 1);
  a[1] = 3;
  for (int i = 2; i <= n; ++i) {
    a[i] = 2 * a[i - 1];
  }
  return a[n];
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}