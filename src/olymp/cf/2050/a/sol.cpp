#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int ans = 0;
    int j = 0;
    while (m > 0 && j < n) {
      int len = a[j].size();
      if (m >= len) {
        ++ans;
        m -= len;
      } else {
        break;
      }
      ++j;
    }
    cout << ans << '\n';
  }
  cout << endl;
  return 0;
}