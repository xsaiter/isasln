#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  const int shift = 1;
  sort(a.begin(), a.end());
  vector<int> dp(n + shift);
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = a[1] - a[0];
  if (n == 2) {
    return dp[n];
  }
  dp[3] = a[2] - a[0];
  if (n == 3) {
    return dp[n];
  }  
  for (int i = 3; i < n; ++i) {      
    dp[i + shift] = min(dp[i - 2 + shift], dp[i - 1 + shift]) + a[i] - a[i - 1];
  }
  return dp[n];
}

int main() {
  int n;
  cin >> n;  
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}