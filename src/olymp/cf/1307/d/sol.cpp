#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int solve(string &s) {
  int res = 0;
  return res;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(k);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pii> p(m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }
  cout << solve(s) << endl;
  return 0;
}