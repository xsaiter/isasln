#include <bits/stdc++.h>

using namespace std;

struct R {
  int sum;  
  vector<int> b;
};

R solve(int n, const vector<int> &a) {
  vector<int> dp(n + 1);    
  dp[0] = 0;
  dp[1] = a[0];
  for (int i = 1; i < n; ++i) {    
    dp[i + 1] = max(dp[i], dp[i - 1]) + a[i];    
  }
  R res;
  res.sum = dp[n];
  for (int i = n; i >= 1; --i) {
    int d = dp[i] - a[i - 1];
    if (d == dp[i - 1]) {
      res.b.push_back(i);
    } else {
      res.b.push_back(i - 1);
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  R r = solve(n, a);
  cout << r.sum << '\n';
  int nb = (int)r.b.size();
  for (int i = 0; i < nb; ++i) {
    cout << r.b[i] << " ";
  }  
  return 0;
}