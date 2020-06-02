#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int z = 0;
  int n = (int)s.size();
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      ++z;
    } else {
      break;
    }
  }
  string res("1");
  if (z > 0) {
    for (int i = 0; i < z; ++i) {
      res += "0";
    }
  }
  cout << res << endl;
  return 0;
}