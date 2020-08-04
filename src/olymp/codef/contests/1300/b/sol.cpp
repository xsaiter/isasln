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
    int m = 2 * n;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
      cin >> a[i];
    }
    sort(begin(a), end(a));  
    int res = abs(a[m / 2 - 1] - a[m / 2]);
    cout << res << "\n";
  }
  cout << endl;
  return 0;
}