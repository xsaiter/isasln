#include <bits/stdc++.h>

using namespace std;

int sum_range(const vector<int> &a, int from, int to) {
  int res = 0;
  for (int i = from; i <= to; ++i) {
    res += a[i];
  }
  return res;
}

int solve(int n, vector<int> &a) {
  vector<vector<int>> dp(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = a[i];
  }
  for (int k = 2; k < n; ++k) {
    for (int i = 0; i < n - k + 1; ++i) {
      int j = i + k;
      dp[i][j] = max(
        a[j] + sum_range(a, i + 1, j) - dp[i + 1][j - 1], 
        a[j] + sum_range(a, i, j - 1) - dp[i][j - 2]
      );
    }
  }
  int fi = dp[0][n - 1];
  int all = sum_range(a, 0, n - 1);
  int se = all - fi;
  if (fi == se) {
    return 0;
  } else if (fi < se) {
    return 1;
  }
  return 2;
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