#include <bits/stdc++.h>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    int i = 0;
    while (i < n && i < m && s[i] == t[i]) {
      ++i;
    }
    int res = i;
    if (i > 0) {
      ++res;
    }
    res += (n - i);
    res += (m - i);
    cout << res << '\n';
  }
  cout << endl;
  return 0;
}