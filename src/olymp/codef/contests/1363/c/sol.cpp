#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

using G = vector<list<int>>;
using pii = pair<int, int>;

bool solve(G &g, int n, int x) {
  vector<pii> d(n);
  vector<bool> marked(n, false);
  int dist = 1;
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    auto jj = g[p];
    for (auto j : jj) {
      if (!marked[j]) {
        marked[j] = true;
        d[j] = {p, dist};
        q.push(j);
      }
    }
    ++dist;
  }
  sort(begin(d), end(d), [](auto &l, auto &r) { return l.se < r.se; });
  int i;
  for (i = 1; i < n; ++i) {
    if (d[i].fi == x) {
      break;
    }
  }
  return i % 2 == 0;
}


void show_tree(G &g, int n) {
  for (int i = 1; i < n; ++i) {
    for (auto &li : g[i]) {
      /*for (int e : li) {
        printf("%d -> %d", i, e);
      }*/      
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    G g(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v); 
      g[v].push_back(u);
    }
    show_tree(g, n);
    cout << (solve(g, n, x) ? "Ayush" : "Ashish") << "\n";
  }
  cout << endl;
  return 0;
}