#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int res = 0;
  int len = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      ++len;
    } else {
      if (len > res) {
        res = len;
      }
      len = 0;
    }
  }
  if (len > res) {
    res = len;
  }
  cout << res << endl;
  return 0;
}