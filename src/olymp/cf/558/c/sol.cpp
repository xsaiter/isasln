#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int solve(int n, vector<int>& a) {
  int m = *(max_element(a.begin(), a.end())) + 1;
  m *= 2;
  vector<int> b(m), c(m);
  for (int i = 0; i < n; ++i) {
    vector<bool> bb(m);    
    int x = a[i];
    bb[x] = true;    
    c[x] += 1;
    int step_x = 0;
    while (x >= 1) {
      int y = x;
      int step_y = step_x;
      while (1) {
        y *= 2;
        if (y >= m) {
          break;
        }
        if (!bb[y]) {
          step_y++;
          b[y] += step_y;
          c[y] += 1;
          bb[y] = true;
        }
      }
      x /= 2;
      step_x++;
      if (!bb[x]) {
        b[x] += step_x;
        c[x] += 1;
        bb[x] = true;
      }
    }
  }  
  int ans = INF;
  for (int i = 0; i < m; ++i) {
    if (c[i] == n) {
      ans = min(ans, b[i]);
    }
  }
  return ans;
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