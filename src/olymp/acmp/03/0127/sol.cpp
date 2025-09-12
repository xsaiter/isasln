#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  int p, q;
  cin >> p >> q;
  vector<vector<int>> dist(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        dist[i][j] = 0;
      } else if (a[i][j] == 1) {
        dist[i][j] = 1;
      } else {
        dist[i][j] = INF;
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {      
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  int ans = dist[p - 1][q - 1];
  if (ans == INF) {
   ans = -1;
  }
  cout << ans << endl;
  return 0;
}