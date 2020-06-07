#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<pii> adj(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, in v;
      cin >> u >> v;
      adj[i] = {u, v};
    }
  }
  return 0;
}