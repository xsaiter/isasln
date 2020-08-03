#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int m) {
  int res = 0;
  return res;
}

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
    cout << solve(a, m) << "\n";
  }
  cout << endl;
  return 0;
}