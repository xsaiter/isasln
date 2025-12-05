#include <bits/stdc++.h>

using namespace std;

const int N = 50;

char f[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> f[i][j];
    }
  }
  int li = N + 1, lj = N + 1, ri = -1, rj = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (f[i][j] == '*') {
        li = min(i, li);
        lj = min(j, lj);
        ri = max(i, ri);
        rj = max(j, rj);
      }
    }
  }
  bool show = false;
  for (int i = 0; i < n; ++i) {  
    show = false;
    for (int j = 0; j < m; ++j) {
      if (i >= li && i <= ri && j >= lj && j <= rj) {
        cout << f[i][j];
        show = true;
      }
    }
    if (show) { cout << "\n"; }
  }  
  return 0;
}