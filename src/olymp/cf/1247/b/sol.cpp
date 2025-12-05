#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int res = 1e6;
    for (int i = 0; i < n; ++i) {            
      int m = i + d;
      if (m <= n) {
        set<int> se;
        for (int j = i; j < m; ++j) {
          se.insert(a[j]);
        }
        res = min(res, (int)se.size());
      }      
    }
    cout << res << "\n";
  }
  cout << endl;
  return 0;
}