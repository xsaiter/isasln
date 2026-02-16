#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int p = -1, q = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] != n - i) {
        p = i;
        break;
      }
    }    
    if (p != -1) {
      for (int i = n - 1; i >= 0; --i) {
        if (a[i] == n - p) {
          q = i;
          break;
        }
      }
    }    
    if (p != -1 && q != -1) {
      reverse(a.begin() + p, a.begin() + q + 1);
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}