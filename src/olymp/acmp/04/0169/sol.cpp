#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1));  
  dp[1][1] = 1;
  for (int j = 2; j <= k; ++j) {
    if (j % 2 == 1) {
      dp[1][j] = dp[1][j] * 3;
    } else {
      dp[1][j] = dp[1][1];
    }    
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (i == j) {
        dp[i][j] = 1;
      } else if (i > j) {
        dp[i][j] = 0;
      } else {
        int d = j - i;
        if (d == 1) {
          dp[i][j] = dp[i][j - 1];
        } else if (d % 2 == 0) { 
          dp[i][j] = dp[i][j - 1] * 2;
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
  }  
  cout << dp[n][k] << endl;
  return 0;
}