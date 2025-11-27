#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  int mi = INT_MIN;
  for (int i = 0; i < n; ++i) {
    int ri = INT_MAX;
    for (int j = 0; j < m; ++j) {      
      if (a[i][j] < ri) {
        ri = a[i][j];
      }
    }
    mi = max(mi, ri);
  }
  int ma = INT_MAX;
  for (int j = 0; j < m; ++j) {
    int ci = INT_MIN;
    for (int i = 0; i < n; ++i) {
      if (a[i][j] > ci) {
        ci = a[i][j];
      }
    }
    ma = min(ma, ci);
  }
  cout << mi << ' ' << ma << endl;
  return 0;
}