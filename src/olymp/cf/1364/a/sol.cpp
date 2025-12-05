#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int c, len = 0, s = 0, p = -1;
    for (int i = 0; i < n; ++i) {
      cin >> c;
      s += c;
      if (s % x > 0) {
        if (p == -1) {
          p = i;
          len = i + 1;
        } else if (i + 1 > len) {
          len = i + 1;
        }
      } else {
        if (p != -1) {
          if (len < i - p) {
            len = i - p;
          }
        }
      }
    }    
    cout << (p != -1 ? len : -1) << "\n";
  }
  cout << endl;
  return 0;
}