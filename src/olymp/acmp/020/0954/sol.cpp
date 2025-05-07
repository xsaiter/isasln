#include <bits/stdc++.h>

using namespace std;

int solve(int k) {
  if (k < 10) {
    return 0;
  }
  vector<int> dp(k + 1, 0);
  dp[0] = 2;
  dp[1] = dp[0];
  dp[2] = dp[1];
  for (int i = 3; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      int rem = j % 10;
      dp[i] = dp[i] + dp[rem];
    }
  }
  return dp[k];
}

int main() {
  int k;
  cin >> k;
  cout << solve(k);
  return 0;
}