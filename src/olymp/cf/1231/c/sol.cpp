#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, vector<vector<int>> &a) {
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 0) {       
        for (int ii = i + 1; ii < n; ++ii) {
          if (a[ii][j] == 0) {
          }
        }
      }
    }
  }
  return ans;
}                                                

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<in>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  cout << solve(n, m, a) << endl;
  return 0;
}