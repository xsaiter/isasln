#include <bits/stdc++.h>

using namespace std;

int M = 1e6;

int solve(int k) {  
  if (k < 10) {
    return 0;
  }  
  vector<int> dp(k + 1, 0);    
  dp[10] = 2;  
  dp[11] = 2;
  dp[12] = 2;  
  for (int i = 13; i <= k; ++i) {
    int rem = i % 10;
    if (rem == 0) {
      dp[i] = 2 % M;
    } else if (rem == 1) {
      dp[i] = (dp[i - 1] * 2) % M;
    } else if (rem == 2) {
      dp[i] = (dp[i - 12] + dp[i - 11] + dp[i - 10]) % M;
    } else {
      dp[i] = 0;
    }
  }
  return dp[k];
}

int main() {
  int k;
  cin >> k;
  cout << solve(k) << endl;
  return 0;
}                                                                           