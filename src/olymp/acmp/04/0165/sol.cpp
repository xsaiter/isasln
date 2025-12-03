#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> dp(n, vector<int>(m));
  dp[0][0] = 1;
  for (int j = 1; j < m; ++j) {
    for (int x = j - 1; x >= 0; --x) {
      if (a[0][x] == j - x) {
        dp[0][j] += dp[0][x];
      }
    }    
  }
  for (int i = 1; i < n; ++i) {
    for (int x = i - 1; x >= 0; --x) {
      if (a[x][0] == i - x) {
        dp[i][0] += dp[x][0];
      }
    }    
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      for (int x = i - 1; x >= 0; --x) {
        if (a[x][j] == i - x) {
          dp[i][j] += dp[x][j];
        }
      }
      for (int x = j - 1; x >= 0; --x) {
        if (a[i][x] == j - x) {
          dp[i][j] += dp[i][x];
        }
      }
    }
  }
  cout << dp[n - 1][m - 1] << endl;
  return 0;
}