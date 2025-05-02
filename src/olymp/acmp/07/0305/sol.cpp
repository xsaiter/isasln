#include <bits/stdc++.h>

using namespace std;

struct Cell {
  int x, y;
};

struct S {
  Cell a, b; 
};

bool inside(int i, int j, int k, const vector<S> &s) {
  for (int p = 0; p < k; ++p) {
    if (s[p].a.x <= i <= s[p].b.x) {
      if (s[p].a.y <= j <= s[p].b.y) {
        return true;
      }
    } 
  }
  return false;
}

int solve(int n, int m, int k, const vector<S> &s) {  
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++i) {
      if (inside(i + 1, j + 1, k, s)) {
        a[i][j] = 1;
      }
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1) {
        dp[i][j] = dp[i][j - 1] + 1;
      }      
    }
  }
  return dp[n][n];
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<S> s(k);
  for (int i = 0; i < k; ++i) {
     cin >> s[i].a.x >> s[i].a.y >> s[i].b.x >> s[i].b.y;
  }
  cout << solve(n, m, k, s) << endl;
  return 0;
}