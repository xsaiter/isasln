#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = 10;
  vector<int> res(m, 0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      int j = 0;
      while (j <= m - 1) {
        if (res[j] == 0) {
          res[j] = 1;
          break;
        }
        ++j;
      }
    } else if (s[i] == 'R') {
      int j = m - 1;
      while (j >= 0) {
        if (res[j] == 0) {
          res[j] = 1;
          break;
        }
        --j;
      }
    } else {
      int j = (int)(s[i] - '0');
      res[j] = 0;
    }
  }
  copy(begin(res), end(res), ostream_iterator<int>(cout, ""));
  return 0;
}