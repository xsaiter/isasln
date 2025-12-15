#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  stack<int> ii;
  vector<int> dp(n);
  int best_len= 0, best_cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      ii.push(i);
    } else if (s[i] == ')') {
      if (ii.empty()) {
        continue;
      }
      int j = ii.top(); ii.pop();
      dp[i] = i - j + 1;
      if (j > 0) {
        dp[i] += dp[j - 1];
      }      
      if (dp[i] > best_len) {
        best_len = dp[i];
        best_cnt = 1;
      } else if (dp[i] == best_len && dp[i] > 0) {
        best_cnt += 1;
      }
    }
  }
  if (best_len == 0) {
    best_cnt = 1;
  }
  cout << best_len << ' ' << best_cnt << endl;
  return 0;
}