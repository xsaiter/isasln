#include <bits/stdc++.h>

using namespace std;

using L = long long;

int main() {
  L k, n;
  cin >> k >> n;
  ++n;
  vector<L> dp(n, 0);
  dp[0] = 1;
  for (L i = 1; i < n; ++i) {
    for (L j = 1; j <= min(k, i); ++j) {
      dp[i] = dp[i] + dp[i - j];
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}