#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<vector<int>>& a) {
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  vector<bool> cc(n + 1, false);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (!cc[j]) {
        cc[j] = true;
      }
    }
  }
  return dp[n][n];
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  cout << solve(n, a) << endl;
  return 0;
}