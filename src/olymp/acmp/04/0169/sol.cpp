#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int m = n + k - 1;
  vector<vector<int>> dp(m + 1, vector<int>(m + 1));
  for (int i = 1; i <= m; ++i) {
    dp[i][i] = 1;
  }
  for (int j = 2; j <= m; ++j) {
    for (int i = 1; i < j; ++i) {
      int ii = i - 1, jj = j - 1;
      if (ii >= 1 && jj >= 1) {
        dp[i][j] += dp[ii][jj];
      }
      ii = i + 1, jj = j - 1;
      if (ii <= m && jj >= 1) {
        dp[i][j] += dp[ii][jj];
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}