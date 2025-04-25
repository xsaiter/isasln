#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int SHOW_INF = 30000;

struct Edge {
  int a, b, w;
};

vector<int> solve(int n, int m, const vector<Edge> &e) {
  vector<int> d(n, INF);  
  d[0] = 0;
  for (int k = 0; k < n - 1; ++k) {
    for (int i = 0; i < m; ++i) {
      if (d[e[i].a] < INF) {
        d[e[i].b] = min(d[e[i].b], d[e[i].a] + e[i].w);
      }
    }
  }
  return d;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> e(m);
  for (int i = 0; i < m; ++i) {
    cin >> e[i].a >> e[i].b >> e[i].w;
    e[i].a--; e[i].b--;
  }  
  vector<int> dist = solve(n, m, e);
  for (int i = 0; i < n; ++i) {
    cout << (dist[i] == INF ? SHOW_INF : dist[i]) << ' ';
  }
  cout << endl;
  return 0;
}