#include <bits/stdc++.h>

using namespace std;

bool is_abc(string &s, int p) {
  return s[p] == 'a' && s[p + 1] == 'b' && s[p + 2] == 'c';
}

int solve(string &s) {
  int n = (int)s.size();
  vector<int> dp(n + 1);
  dp[3] = (is_abc(s, 0) ? 1 : 0);

  return dp[n];
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}