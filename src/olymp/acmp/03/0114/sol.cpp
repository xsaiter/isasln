#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k) {  
  vector<int> dp(n + 1);
  dp[1] = k;  
  for (int i = 2; i <= n; ++i) {
    int x = k;
    if (i == n) {
      x = k - 1;
    } else {
      if (i % 2 == 0) {
        x = k - 1;
      } else {
        x = k;
      }
    }    
    dp[i] = dp[i - 1] * x;
  }
  return dp[n];
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << solve(n, k) << endl;
  return 0;
}