#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  vector<int> dp(n + 1);
  dp[1] = 2;  
  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1] + i;
  }
  return dp[n];
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}