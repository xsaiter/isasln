#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int y, int x) {
  int res = 0;
  int d = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == y) {
      res += x;
      break;
    }
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  int y, x;
  cin >> y >> x;
  cout << solve(n, m, y, x) << endl;
  return 0;
}