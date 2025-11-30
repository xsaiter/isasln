#include <bits/stdc++.h>

using namespace std;

int MOD = 1e6;

int solve(int k) {   
  vector<vector<int>> dp(k + 11, vector<int>(4));
  dp[10][1] = 2;
  for (int h = 10; h < k + 1; ++h) {
    for (int s = 1; s < 4; ++s) {
      if (dp[h][s] == 0) {
        continue;
      }
      if (s < 3 and h + 1 <= k) {
        dp[h + 1][s + 1] = (dp[h + 1][s + 1] + dp[h][s]) % MOD;
      }
      if (h + 10 <= k) {
        dp[h + 10][1] = (dp[h + 10][1] + dp[h][s]) % MOD;
      }            
    }
  }
  int ans = 0;
  for (int j = 0; j < 4; ++j) {
    ans += dp[k][j];
  }
  return ans % MOD;    
}

int main() {
  int k;
  cin >> k;
  cout << solve(k) << endl;
  return 0;
}                                                                           