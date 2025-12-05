#include <bits/stdc++.h>

using namespace std;
using M = vector<vector<int>>;

void show_matrix(const M &m, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << m[i][j];
    }
    cout << "\n";
  }
}

bool is_failed(const M &m, int n, int i, int j) {
  return m[i][j] == 1 && m[i + 1][j] == 0 && m[i][j + 1] == 0;
}

bool solve(const M &m, int n) {
  for (int i = n - 2; i >= 0; --i) {
    for (int j = n - 2; j >= 0; --j) {
      if (is_failed(m, n, i, j)) return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    M m(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < n; ++j) {
        m[i][j] = (s[j] == '0') ? 0 : 1;
      }
    }
    cout << (solve(m, n) ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}