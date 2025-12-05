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
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      res = max(0LL, res + a[i]);
    }
    cout << res << "\n";
  }
  cout << endl;
  return 0;
}