#include <bits/stdc++.h>

using namespace std;

int solve(const vector<vector<int> &a, int n) {  
  set<int> rows;
  set<int> cols;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i][j - 1]);
    }
  }
  return dp[n][n];
}

int main() {
  int n;
  cin >> n;
  vector<vector<int> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j< n; ++j) {
      cin >> a[i][j];
    }
  }
  cout << solve(a, n) << endl;
  return 0;
}