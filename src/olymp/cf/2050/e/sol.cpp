#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int cost(char x, char c) {
  if (x != c) {
    return 1;
  }
  return 0;
}

int solve(const string &a, const string &b, const string &c) {
  int na = (int)a.size();
  int nb = (int)b.size();  
  vector<vector<int>> dp(nb + 1, vector<int>(na + 1, INF));
  dp[0][0] = 0;
  for (int j = 1; j <= na; ++j) {
    dp[0][j] = dp[0][j - 1] + cost(a[j - 1], c[j - 1]);
  }
  for (int i = 1; i <= nb; ++i) {
    dp[i][0] = dp[i - 1][0] + cost(b[i - 1], c[i - 1]);
  }
  for (int i = 1; i <= nb; ++i) {
    for (int j = 1; j <= na; ++j) {
      int ci = i + j - 1;      
      dp[i][j] = min(dp[i][j - 1] + cost(a[j - 1], c[ci]), dp[i - 1][j] + cost(b[i - 1], c[ci]));
    }
  }
  return dp[nb][na];
}        

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << '\n';
  }
  cout << endl;
  return 0;
}