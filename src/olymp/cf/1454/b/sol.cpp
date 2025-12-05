#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int solve(vector<int> &a, int n) {  
  if (n == 0) return -1;
  if (n == 1) return 1;
  vector<pii> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = {a[i], i + 1};
  }
  sort(begin(b), end(b), [](const auto &l, const auto &r) { return l.fi < r.fi; });  
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      if (b[i].fi != b[i + 1].fi) return b[i].se;
    } else if (i == n - 1) {
      if (b[i].fi != b[i - 1].fi) return b[i].se;
    } else {
      if (b[i].fi != b[i + 1].fi && b[i].fi != b[i - 1].fi) return b[i].se;
    }
  }  
  return -1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(a, n) << "\n";
  }
  cout << endl;
  return 0;
}