#include <bits/stdc++.h>

using namespace std;
using M = vector<vector<int>>;

struct R {
  int a, b;
};

struct RCmp {
  bool operator ()(const R &x, const R &y) const {   
    return min(x.a, x.b) < min(y.a, y.b);
  }
};

void sort(vector<R> &vec) {
  sort(begin(vec), end(vec), RCmp());
}

int solve(int n, int k, vector<R> &rr) {
  int res = 0;
  sort(rr);
  int i = 0;
  R r = rr[i];
  while (k > 0) {     
    if (r.a < r.b) {
      res += r.a;
      --k;
      r.b--;
      if (r.b == 0) {
        k -= r.a;
      }
    } else if (r.a > r.b) {
      res += r.b;
      --k;
      r.a--;
      if (r.a == 0) {
        k -= r.b;
      }
    } else {
      res += r.a;
      --k;
      r.b--;
      if (r.b == 0) {
        k -= r.a;
      }
    }
    if (r.a == 0 || r.b == 0) {
      ++i;
      if (i == n) {
        break;
      }
      r = rr[i];
    }    
  }
  if (k > 0) {
    return -1;
  }
  return res;
}

int solve2(int n, int k, const vector<R> &rr) {  
  // i - number of rects
  // j - number of points
  M dp(n + 1, vector<int>(k + 1, INT_MAX));  
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int a = rr[i].a;
    int b = rr[i].b;
    int cost = 0;    
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost);
      if (a >= b) {
        --a; cost += b;
      } else {
        --b; cost += a;
      }
    }    
  }
  return dp[n][k];
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
    cout << solve2(n, k, rr) << '\n';
  }
  cout << endl;
  return 0;
}