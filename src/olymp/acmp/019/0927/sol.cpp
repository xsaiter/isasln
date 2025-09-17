#include <bits/stdc++.h>

using namespace std;

int MOD = 7 + 1e9;
int M = 10;

int len(const string& s) {
  return (int)s.size();
}

int dig(char c) {
  return (int)c - (int)'0';
}

int last_d(int x) {
  string s = to_string(x);
  int n = len(s);
  return dig(s[n - 1]);
}

int solve(int c) {
  string s = to_string(c);
  int n = len(s);
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(M, vector<int>(M)));

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {      
      int d = i + j;
      if (d == dig(s[n - 1])) {
        dp[n][i][j] += 1;
      }
    }
  }  

  for (int k = n - 1; k >= 1; --k) {
    int start = 0;
    if (k == 1) {
      start = 1;
    }
    for (int i = start; i < M; ++i) {
      for (int j = start; j < M; ++j) {
        int d = i + j;
        if (d == dig(s[k])) {          
          for (int kk = k + 1; kk <= n; ++kk) {
            for (int ii = 0; ii < M; ++ii) {
              for (int jj = 0; jj < M; ++jj) {
                dp[k][i][j] += dp[kk][ii][jj];
              }
            }
          }          
        }
      }
    }
  }

  int res = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      res += dp[1][i][j] % MOD;
    }
  }
  return res;
}

int main() {
  int c;
  cin >> c;
  cout << solve(c) << endl;
  return 0;
}