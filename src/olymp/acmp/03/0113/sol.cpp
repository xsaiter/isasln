#include <bits/stdc++.h>

using namespace std;

using M = vector<vector<int>>;

const int INF = 1e9;

template<typename T>
T min3(T &a, T &b, T &c) {
  return min(min(a, b), c);
}

int solve(int n, M &a) {  
  vector<vector<int>> dp(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i) {
    dp[i][0] = a[i][0];
  }
  for (int i = 0; i < n; ++i) {
    dp[0][i] = a[0][i];
  }
  for (int i = 1; i < n; ++i) {        
    for (int j = 1; j < n; ++j) {
      if (a[i][j] == 0) {
        dp[i][j] = a[i][j];
      } else {
        dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
      }
    }
  }
  int side = -INF;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
       side = max(side, dp[i][j]);
    }
  }  
  return side * side;
}

int main() {
  int n;
  cin >> n;
  M a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] == '0') {
        a[i][j] = 0;
      } else {
        a[i][j] = 1;
      }
    }
  }
  cout << solve(n, a) << endl;
  return 0;
}