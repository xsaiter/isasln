#include <bits/stdc++.h>

using namespace std;

struct R {
  int nz;
  string path;
};

int cnt_ff(int n, int p) {
  int ans = 0;
  while (n % p == 0) {
    ans += 1;
    n /= p;
  }
  return ans;
}

R solve(int n, vector<vector<int>>& a) {
  vector<vector<int>> dp2(n, vector<int>(n));
  vector<vector<int>> dp5(n, vector<int>(n));

  vector<vector<char>> di(n, vector<char>(n));

  vector<vector<int>> f2(n, vector<int>(n));
  vector<vector<int>> f5(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      f2[i][j] = cnt_ff(a[i][j], 2);
      f5[i][j] = cnt_ff(a[i][j], 5);
    }
  }

  dp[0][0] = zz(a[0][0], bb);
  bb[0][0].n2 = 0; bb[0][0].n5 = 0;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = dp[i - 1][0] + zz(a[i][0], bb);
    di[i][0] = 'D';
  }
  for (int j = 1; j < n; ++j) {
    dp[0][j] = dp[0][j - 1] + zz(a[0][j], bb);
    di[0][j] = 'R';
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      int x = dp[i - 1][j] + zz(a[i][j], bb);
      int y = dp[i][j - 1] + zz(a[i][j], bb);
      if (x < y) {
        dp[i][j] += x;
        di[i][j] = 'D';
      } else {
        dp[i][j] += y;
        di[i][j] = 'R';
      }
    }
  }
  ostringstream oss;
  int ii = n - 1, jj = n - 1;
  while (ii != 0 || jj != 0) {
    oss << di[ii][jj];
    if (di[ii][jj] == 'D') {
      --ii;
    } else if (di[ii][jj] == 'R') {
      --jj;
    }
  }
  string s = oss.str();
  reverse(s.begin(), s.end());
  return R{ .nz = dp[n - 1][n - 1], .path = s };
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  R r = solve(n, a);
  cout << r.nz << '\n';
  cout << r.path << endl;
  return 0;
}