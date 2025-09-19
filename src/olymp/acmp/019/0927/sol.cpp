#include <bits/stdc++.h>

using namespace std;

int MOD = 7 + 1e9;
int M = 10;

struct R {
  int i, j;
};

R new_r(int i, int j) {
  return R{ .i = i, .j = j };
}

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
  vector<vector<R>> a(n + 1);
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      int d = i + j;
      if (d == dig(s[n - 1])) {
        a[n].push_back(new_r(i, j));
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
        if (d == dig(s[k - 1])) {
          a[k].push_back(new_r(i, j));
        }
      }
    }
  }
  for (int k = n - 1; k >= 0; --k) {    
  }
  vector<int> dp(n + 1);
  for (int k = n - 1; k >= 1; --k) {
    dp[k] = dp[k + 1] * 2;
  }
  return dp[1];
}

int main() {
  int c;
  cin >> c;
  cout << solve(c) << endl;
  return 0;
}