#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int len(int x, int y, int n) {
 return (x - 1) * n + y - 1;
}

bool valid(int x, int y, int n) {
  return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
  int N;
  cin >> N;
  int x1, y1;
  cin >> x1 >> y1;
  int x2, y2;
  cin >> x2 >> y2;
  int p = len(x1, y1, N);
  int q = len(x2, y2, N);   
  int n = N * N;
  vector<vector<int>> adj(n);
  auto add_to_adj = [&](int src, int x, int y) {
    if (valid(x, y)) {
      int dest = len(x, y, N);
      adj[src].push_back(dest);
    }
  };
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int src = len(i, j, N);      
      add_to_adj(src, i + 1, j + 2);
      add_to_adj(src, i + 1, j - 2);
      add_to_adj(src, i - 1, j + 2);
      add_to_adj(src, i - 1, j - 2);

      add_to_adj(src, i + 2, j + 1);
      add_to_adj(src, i + 2, j - 1);
      add_to_adj(src, i - 2, j + 1);
      add_to_adj(src, i - 2, j - 1);
    }
  }
  vector<vector<int>> dist(n, vector<int>(n));
  for (int i = 0 ; i < n; ++i) {
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
   for (int i = 0 ; i < n; ++i) {
     for (int j =0 ; j < n ;++j) {
       dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
     }
   }
  }
  return 0;
}