#include <bits/stdc++.h>

using namespace std;

struct A {
  int t, p, j;

  int vi() const {
    if (t == 1) {
      return 1;
    }
    return 2;
  }
};

void solve(int n, int v, const vector<A> &a) {
  vector<vector<int>> dp(n + 1, vector<int>(v + 1));  
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < v + 1; ++j) {
      if (j >= a[i - 1].vi()) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1].vi()] + a[i - 1].p);        
      } else {        
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  vector<int> b;
  int ii = n, jj = v;
  while (ii > 0 && jj > 0) {
     if (dp[ii][jj] == dp[ii - 1][jj]) {
       --ii;       
     } else {
       b.push_back(a[ii - 1].j);  
       jj -= a[ii - 1].vi();
       --ii;
     }
  }
  reverse(b.begin(), b.end());
  cout << dp[n][v] << '\n';
  int nb = (int)b.size();
  for (int i = 0; i < nb; ++i) {
    cout << b[i] << ' ';
  }
  cout << endl;
}

int main() {
  int n, v;
  cin >> n >> v;
  vector<A> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].t >> a[i].p;
    a[i].j = i + 1;
  }
  solve(n, v, a);  
  return 0;
}