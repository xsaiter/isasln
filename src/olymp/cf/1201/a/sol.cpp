#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  int res = 0;
  for (int j = 0; j < m; ++j) {
    vector<int> x(5, 0);
    for (int i = 0; i < n; ++i) {
      char c = s[i][j];
      if (c == 'A') ++x[0];
      else if (c == 'B') ++x[1];
      else if (c == 'C') ++x[2];
      else if (c == 'D') ++x[3];
      else if (c == 'E') ++x[4];
    }
    sort(begin(x), end(x), greater<int>());
    res += a[j] * x[0];
  }
  cout << res << endl;
  return 0;
}