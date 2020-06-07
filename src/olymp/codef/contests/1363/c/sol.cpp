#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

using G = vector<list<int>>;
using pii = pair<int, int>;

int solve(G &g, int n, int x) {
  if (g.size() == 0 || g[x].size() <= 1) {
    return 1;
  }
  vector<pii> d(n);
  vector<bool> marked(n, false);
  queue<int> q;
  marked[x] = true;
  d[x] = {x, 0};
  q.push(x);
  while (!q.empty()) {
    auto s = q.front();
    q.pop();
    for (auto u : g[s]) {
      if (!marked[u]) {
        marked[u] = true;
        d[u] = {s, d[s].se + 1};
        q.push(u);
      }
    }
  }
  sort(begin(d), end(d), [](auto &l, auto &r) { return l.se > r.se; });
  int ones = 0;
  int len = n - 2;
  for (int i = 0; i < len; ++i) {
    if (d[i].se == 1) {
      ++ones;
    }
  }
  int steps = len - ones;
  if (steps % 2 == 0) {
    return ((ones % 2 == 1) ? 1 : 2);
  } else {
    return ((ones % 2 == 0) ? 1 : 2);
  }
}

void show_tree(const G &g, int n) {
  for (int i = 1; i < n; ++i) {
    for (const auto &e : g[i]) {
      printf("%d -> %d", i, e);
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
    ++n;
    G g(n);
    for (int i = 1; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cout << (solve(g, n, x) == 1 ? "Ayush" : "Ashish") << "\n";
  }
  cout << endl;
  return 0;
}