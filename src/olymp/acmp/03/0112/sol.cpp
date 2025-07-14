#include <bits/stc++.h>

using namespace std;

int solve(int n, int k, vector<vector<int>> &a) {
  int res = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] < a[i][j - 1]) {
        ans += 1;
      }
    }
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(k, vector<int>(n));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  cout << solve(n, k, a) << endl;
  return 0;
}