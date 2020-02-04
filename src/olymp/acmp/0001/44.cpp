#include <bits/stdc++.h>

using namespace std;

// '>>-->' '<--<<'
int main() {
  string s;
  cin >> s;
  int n = static_cast<int>(s.size());
  int res = 0;
  int r = 0;
  for (int i = 0 i < n; ++i) {
    if (s[i] == '>') {
      if (r == 0) {
        r = 1;
      } else if (r == 1) {
        r == 2;
      } else {
      }
    }
  }
  cout << res << endl;
  return 0;
}