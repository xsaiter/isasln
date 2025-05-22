#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;  
};

struct P_cmp {
  bool operator()(const P &a, const P &b) const {
    if (a.x != b.x) {
      return a.x < b.x;
    }
    return a.y < b.y;
  }
};

using S = set<P, P_cmp>;
using G = vector<vector<int>>;

int gnum(int x, int y, int m) {
  return x * m + y;
}

bool keep(const S &ss, const P &p) {
  return ss.find(p) != ss.end();
}

bool keep(const S &ss, int x, int y) {  
  return keep(ss, { .x = x, .y = y });
}

void dfs(int s, const G &g, vector<bool> &vis) {
  if (vis[s]) {
    return;
  }
  vis[s] = true;
  for (auto u : g[s]) {
    dfs(u, g, vis);
  }
}

int solve(int n, int m, int k, const vector<P> &v) {
  int N = n * m;
  S ss(begin(v), end(v));
  G g(N, vector<int>());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {      
      if (keep(ss, i, j)) {
        continue;
      }      
      int a = gnum(i, j, m);
      int b = -1;      
      if (j != m - 1) {
        if (!keep(ss, i, j + 1)) {
          b = gnum(i, j + 1, m);      
          g[a].push_back(b);
          g[b].push_back(a);
        }
      }
      if (i != n - 1) {
        if (!keep(ss, i + 1, j)) {
          b = gnum(i + 1, j, m);
          g[a].push_back(b);
          g[b].push_back(a);
        }
      }
    }
  }  
  int ans = 0;
  vector<bool> vis(N, false);
  for (int i = 0; i < k; ++i) {
    int j = gnum(v[i].x, v[i].y, m);
    vis[j] = true;
  }
  for (int i = 0; i < N; ++i) {
    if (!vis[i]) {
      dfs(i, g, vis);
      ans += 1;
    }
  }  
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  int k;
  cin >> k;
  vector<P> v(k);
  for (int i = 0; i < k; ++i) {
    cin >> v[i].x >> v[i].y;
    v[i].x -= 1; v[i].y -= 1;
  }  
  cout << solve(n, m, k, v) << endl;
  return 0;
}