#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int y, int x) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      for (int j = 1; j <= m; ++j) {
        if (i == y && j == x) {
          return ans;
        }
        ++ans;
      }
    } else {
      for (int j = m; j >= 1; --j) {
        if (i == y && j == x) {
          return ans;
        }
        ++ans;
      }
    }    
  }
  return ans;
}

int main() {
  int n, m, y, x;
  cin >> n >> m >> y >> x;
  cout << solve(n, m, y, x) << endl;
  return 0;
}