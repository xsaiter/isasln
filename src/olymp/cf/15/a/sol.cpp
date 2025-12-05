#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  vector<pii> v(n);
  for (int i = 0; i < n; ++i) {
    int x, a;
    cin >> x >> a;
    v[i] = {x, a};
  }
  sort(begin(v), end(v), [](const auto &l, const auto &r) { return l.fi < r.fi; });
  int res = 0;
  for (int i = 0; i < n - 1; ++i) {    
    double l = v[i].fi + (double)v[i].se / 2;
    double r = v[i + 1].fi - (double)v[i + 1].se / 2;
    if (r - l == (double)t) { ++res; } 
    else if (r - l > (double)t) { res += 2; }
  }
  res += 2;
  cout << res << endl;
  return 0;
}