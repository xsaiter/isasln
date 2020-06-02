#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  const int n = a.size();
  const int m = b.size();
  int res = 0;
  if (n >= m) {
    for (int i = 0; i <= n - m; ++i) {
      bool ok = false;
      int j;
      for (int k = 0; k < m && !ok; ++k) {
        for (j = 0; j < m && !ok; ++j) {
          int p = (j + k) % m;
          if (a[i + p] != b[j]) {
            break;
          }
        }
        if (j == m) {
          ok = true;
          ++res;
          break;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}