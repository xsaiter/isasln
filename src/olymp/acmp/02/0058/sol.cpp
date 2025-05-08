#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int m, vector<vector<int>> &a) {
  if (n <= 1 || m <= 1) {
    return true;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    cout << (solve(n, m, a) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}