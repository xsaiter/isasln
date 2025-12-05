#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int solve(vector<pii> &v, int n, int m) {
  int res = 0;
  sort(begin(v), end(v),
       [](const auto &l, const auto &r) { return l.se > r.se; });
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < v[i].fi; ++j) {
      res += v[i].se;
      --n;
      if (n == 0)
        return res;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pii> v(m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    v[i] = {a, b};
  }
  cout << solve(v, n, m) << endl;
  return 0;
}