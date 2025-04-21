#include <bits/stdc++.h>

using namespace std;
using M = vector<vector<int>>;

struct R {
  int a, b;
};

const int INF = 1e9;

int solve(int n, int k, const vector<R> &rr) {    
  vector<int> dp(k + 1, INF);  
  dp[0] = 0;
  int ii = 0;
  while (ii < n) {
    int a = rr[ii].a;
    int b = rr[ii].b;
    int cnt = 0;
    int cost = 0;
    vector<int> q(k + 1, INF);
    q[0] = 0;
    while (cnt < k && (a > 0 || b > 0)) {
      if (a < b) {
        swap(a, b);
      }
      ++cnt;
      cost += b;
      --a;
      q[cnt] = cost;
    }    
    for (int i = k; i >= 0; --i) {
      dp[i] = min(dp[i], q[i]);
      for (int j = 1; j <= k; ++j) {        
        for (int ii = 1; ii <= k - j; ++ii) {
          if (j + ii == i) {
            dp[i] = min(dp[i], dp[j] + q[ii]);              
          }
        }        
      }
    }    
    ++ii;
  }
  return (dp[k] == INF ? -1 : dp[k]);
}

int main() {
  int t;
  cin >> t;  
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<R> rr(n);
    for (int i = 0; i < n; ++i) {
      cin >> rr[i].a >> rr[i].b;
    }
    cout << solve(n, k, rr) << '\n';
  }
  cout << endl;
  return 0;
}