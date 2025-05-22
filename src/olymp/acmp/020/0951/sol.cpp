#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct P {
  int x, y;  
};

int dist(const P &a, const P &b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int solve(int n, int m, int k, const vector<P> &v) {
  int ans = -INF;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      P u { .x = i + 1, .y = j + 1 };
      int d = INF;
      for (int q = 0; q < k; ++q) {        
        d = min(d, dist(u, v[q]));
      }
      ans = max(ans, d);
    }    
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  int k;
  cin >> k;
  vector<P> v(k);
  for (int i = 0; i < k; ++i) {
    cin >> v[i].x >> v[i].y;
  }  
  cout << solve(n, m, k, v) << endl;
  return 0;
}