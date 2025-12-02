#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int>& a) {
  vector<vector<int>> dp(n, vector<int>(n));
  for (int x = 0; x < n; ++x) {
    dp[x][n - 1 - x] = a[x];
  }
  for (int k = n - 1; k >= 0; --k) {
    for (int x = 0; x < k; ++x) {
      dp[x][k - 1 - x] = max(dp[x][k - 2 - x], dp[x + 1][k - 1 - x]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << dp[0][i] << ' ';
  }
  cout << '\n';
  return dp[0][0];
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}