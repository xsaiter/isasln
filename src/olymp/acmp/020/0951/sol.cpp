#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct P {
  int x, y;  
};

int dist(const P &a, const P &b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int dist_far(int n, int m, P &a) {
  int res = -INF;
  res = max(res, dist({.x = 1, .y = 1}, a));
  res = max(res, dist({.x = 1, .y = m}, a));
  res = max(res, dist({.x = n, .y = 1}, a));
  res = max(res, dist({.x = n, .y = m}, a));
  return res;
}

int solve2(int n, int m, int k, vector<P> &v) {
  vector<int> dd(k);
  for (int i = 0; i < k; ++i) {
    dd[i] = dist_far(n, m, v[k]);
  }
}

int gnum(int x, int y, int m) {
  return x * m + y;
}

int solve(int n, int m, int k, vector<P> &v) {
  int N = n * m;
  vector<vector<int>> adj(N, vector<int>());  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a, b;
      a = gnum(i, j, m);
      
      if (j != m - 1) {
        b = gnum(i, j + 1, m);      
        adj[a].push_back(b);
        adj[b].push_back(a);
      }

      if (i != n - 1) {
        b = gnum(i + 1, j, m);
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
    }
  }  
  queue<int> q;
  vector<bool> vis(N);
  vector<int> dist(N);
  for (int i = 0; i < k; ++i) {    
    int s = gnum(v[i].x - 1, v[i].y - 1, m);
    q.push(s);
    vis[s] = true;
    dist[s] = 0;
  }  
  while (!q.empty()) {
    int s = q.front(); q.pop();
    for (int u : adj[s]) {
      if (!vis[u]) {
        vis[u] = true;
        q.push(u);
        dist[u] = dist[s] + 1;
      }
    }
  }
  return *max_element(begin(dist), end(dist));  
}

int main() {
  int n, m;
  cin >> n >> m;
  int k;
  cin >> k;
  vector<P> v(k);
  for (int i = 0; i < k; ++i) {
    cin >> v[i].x >> v[i].y;
  }  
  cout << solve(n, m, k, v) << endl;
  return 0;
}