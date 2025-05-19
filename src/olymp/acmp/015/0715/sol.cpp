#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, const vector<string> &a, const vector<string> &b) {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == b[i][j]) {
        ans += 1;
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<string> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  cout << solve(n, m, a, b) << endl;
  return 0;
}