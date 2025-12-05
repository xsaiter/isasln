#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2 != a[i] % 2) {
        if (i % 2) ++x; else ++y;
      }
    }
    if (x != y) {
      cout << -1;
    } else {
      cout << x;
    }
    cout << "\n";
  }
  cout << endl;
  return 0;
}