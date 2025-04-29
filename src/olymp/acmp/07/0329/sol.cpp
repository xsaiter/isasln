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
  int j = n;  
  vector<int> b;
  while (j >= 1) {
    int d = dp[j] - a[j - 1];
    if (d == dp[j - 1]) {
      b.push_back(j);
      j -= 1;
    } else if (d == dp[j - 2]) {            
      b.push_back(j);
      j -= 2;
    }    
  }
  reverse(b.begin(), b.end());
  res.b=  b;
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