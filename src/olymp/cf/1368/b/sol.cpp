#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 k;
  cin >> k;
  string s = "codeforces";
  int n = (int)s.size();
  int pos = n;
  i64 x = 1, y = 1, len = 1;  
  while (y < k) {
    x = 1, y = 1; ++len;
    for (int i = 0; i < n; ++i) {
      x *= len;
      int j = n - 1 - i;
      y = 1;
      while (j--) y *= (len - 1);
      y *= x;
      if (y >= k) {
        pos = i;
        break;
      }
    }    
  }
  for (int j = 0; j < n; ++j) {
    int t = (j <= pos) ? len : (len - 1);    
    while (t--) cout << s[j];
  }
  cout << endl;
  return 0;
}