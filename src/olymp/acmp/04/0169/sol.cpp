#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(L n, L k) {
  if (n > k) {
    return 0;
  }
  if (n == k) {
    return 1;
  }  
  vector<vector<L>> dp(n, vector<L>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      for (int ii = 0; ii < min(i, j); ++ii) {
        for (int jj = 0; jj < min(i, j); ++jj) {
          dp[i][j] = dp[i][j] + dp[ii][jj];
          dp[i][j] += dp[ii][jj];
        }
      }      
    }
  }
  return dp[n - 1][k - 1];
}

int main() {
  L n, k;
  cin >> n >> k;
  cout << solve(n, k) << endl;
  return 0;
}