#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    int m = 2 * n;
    vector<int> h(m);
    for (int i = 0; i < m; ++i) {
      cin >> h[i];
    }
    bool res = true;
    sort(begin(h), end(h));
    for (int i = 0; i < n; ++i) {
      if (h[n + i] < h[i] + x) {
        res = false;
        break;
      }
    }
    cout << (res ? "YES" : "NO") << '\n';
  }  
  cout << endl;
  return 0;
}