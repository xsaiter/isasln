#include <bits/stdc++.h>

using namespace std;

using M = vector<vector<int>>;
const int INF = 1e9;

int solve(int n, M &a) {
  M b(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {      
      if (i == j) {
        b[i][j] = 0;
      } else if (a[i][j] == -1) {
        b[i][j] = INF;
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
  int ans = -INF;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (b[i][j] < INF) {
        ans = max(ans, b[i][j]);
      }
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  M a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <n; ++j) {
      cin >> a[i][j];
    }
  }
  cout << solve(n, a) << endl;
  return 0;
}