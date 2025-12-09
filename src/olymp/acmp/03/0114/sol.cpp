#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k) {  
  vector<int> dp(n + 1);
  dp[0] = 1;
  dp[1] = k - 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
  }  
  return dp[n];
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << solve(n, k) << endl;
  return 0;
}