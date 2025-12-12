#include <bits/stdc++.h>

using namespace std;

using L = long long;
const L INF = 1e18;

L solve(int n, const vector<L> &a, const vector<L> &b) {
  vector<L> dp_mi(n, INF), dp_mx(n, -INF);
  dp_mi[0] = min(-a[0], b[0]);
  dp_mx[0] = max(-a[0], b[0]);
  for (int i = 1; i < n; ++i) {
    L mx_0 = dp_mx[i - 1] - a[i];
    L mx_1 = b[i] - dp_mi[i - 1];
    L mi_0 = dp_mi[i - 1] - a[i];
    L mi_1 = b[i] - dp_mx[i - 1];
    dp_mi[i] = min(mi_0, mi_1);
    dp_mx[i] = max(mx_0, mx_1);
  }
  return dp_mx[n - 1];
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<L> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }    
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cout << solve(n, a, b) << '\n';
  }
  cout << endl;
  return 0;
}