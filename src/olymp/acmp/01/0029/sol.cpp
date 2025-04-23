#include <bits/stdc++.h>
 
using namespace std;

int jump1(const vector<int> &a, int i) {
  return abs(a[i] - a[i - 1]);
}

int jump2(const vector<int> &a, int i) {
  return 3 * abs(a[i] - a[i - 2]);
}
 
int solve(int n, const vector<int> &a) {  
  vector<int> dp(n, 0);      
  dp[1] = jump1(a, 1);
  for (int i = 2; i < n; ++i) {    
    dp[i] = min(dp[i - 1] + jump1(a, i), dp[i - 2] + jump2(a, i));    
  }
  return dp[n - 1];
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