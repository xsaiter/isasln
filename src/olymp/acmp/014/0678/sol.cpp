#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  int ans = 1;  
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      if (ans == 1) {
        ans = 2;
      } else if (ans == 2) {
        ans = 1;
      }
    } else if (s[i] == 'B') {
      if (ans == 2) {
        ans = 3;
      } else if (ans == 3) {
        ans = 2;
      }
    } else if (s[i] == 'C') {
      if (ans == 1) {
        ans = 3;
      } else if (ans == 3) {
        ans = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}