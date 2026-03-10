#include <bits/stdc++.h>

using namespace std;

int val(int i, int j, int n) {
  return (i - 1) * n + j;
}

int solve(int n) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int cur = val(i, j, n);
      if (j > 1) {
        cur += val(i, j - 1, n);
      }
      if (i > 1) {
        cur += val(i - 1, j, n);
      }
      if (j < n) {
        cur += val(i, j + 1, n);
      }
      if (i < n) {
        cur += val(i + 1, j, n);
      }
      ans = max(ans, cur);
    }
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << solve(n) << '\n';
  }
  cout << endl;
  return 0;
}