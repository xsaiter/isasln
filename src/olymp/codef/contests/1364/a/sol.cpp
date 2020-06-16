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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
      s += a[i];
      b[i] = ((s % x) == 0 ? 0 : 1);
    }
    int len = 0;
    bool ok = false;
    for (int i = n - 1; i >= 0; --i) {
      if (b[i] == 1) {
        len = i + 1;
        ok = true;
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (b[i] == 0) {
        if (len - 1 < i) {
          for (int j = 0; j < i; ++j) {
            if (b[j] == 1) {
              if (i - j > len) {
                len = i - j;
                ok = true;
                break;
              }
            }
          }
        }
      }
    }
    cout << (ok ? len : -1) << "\n";
  }
  cout << endl;
  return 0;
}