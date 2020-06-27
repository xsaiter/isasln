#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using psi = pair<string, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<psi> v(n);
  for (int i = 0; i < n; ++i) {
    string s; int a;
    cin >> s >> a;
    v[i] = {s, a};
  }
  sort(begin(v), end(v), [](const auto &l, const auto &r) { return l.se < r.se; });
  if (v[0].se > 0) {
    cout << -1;
  } else {
    vector<psi> res(n);
    for (int i = 0; i < n; ++i) {
      
    }
    for (int i = 0; i < n; ++i) {
      cout << res[i].fi << " " << res[i].se << '\n';
    }
  }
  cout << endl;
  return 0;
}