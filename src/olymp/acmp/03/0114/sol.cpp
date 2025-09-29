#include <bits/stdc++.h>

using namespace std;

/*
x = 9 * 9 + 9
(k - 1) * (k - 1) + (k - 1)
0000 11111 22222 99999
1239 01239 01239 01239
*/
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