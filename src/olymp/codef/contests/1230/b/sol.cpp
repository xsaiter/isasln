#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n == 1) {
    if (k > 0) {
      s[0] = '0';
    }
  } else {
    if (k > 0) {
      if (s[0] != '1') {
        s[0] = '1';
        --k;
      }
      if (k > 0) {
        for (int i = 1; i < n; ++i) {
          if (s[i] != '0') {
            s[i] = '0';
            --k;
          }
          if (k == 0)
            break;
        }
      }
    }
  }
  cout << s << endl;
  return 0;
}