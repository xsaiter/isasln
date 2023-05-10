#include <bits/stdc++.h>

using namespace std;

using R = long long;

R inf = LLONG_MAX;

R cost(int i, int j, int m) {
  return (i - 1) * m + j;
}

R solve(int n, int m) {  
  R res = (m - 1) * m / 2;
  for (int i = 1; i <= n; ++i) {
    res += m * i;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << '\n';
  }
  cout << endl;
  return 0;
}