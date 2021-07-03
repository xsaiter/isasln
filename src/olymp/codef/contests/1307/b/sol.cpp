#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int n, int x) {
  if (count(begin(a), end(a), x)) {
    return 1;
  }
  int mx = *max_element(begin(a), end(a));
  return max(2, (x + mx - 1) / mx);
}

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
    cout << solve(a, n, x) << "\n";
  }
  cout << endl;
  return 0;
}