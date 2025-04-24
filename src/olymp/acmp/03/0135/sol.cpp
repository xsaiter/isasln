#include <bits/stdc++.h>

using namespace std;

using M = vector<vector<int>>;

M solve(int n, M &a) {
  M b(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        b[i][j] = 0;
      } else {
        b[i][j] = a[i][j];
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
      }
    }
  }
  return b;
}

int main() {
  int n;
  cin >> n;
  M a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  M b = solve(n, a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << b[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}