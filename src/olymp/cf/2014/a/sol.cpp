#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k, const vector<int> &a) {
  int cur = 0;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      if (cur > 0) {
        --cur;
        ++res;
      }
    }
    if (a[i] >= k) {
      cur += a[i];
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, k, a) << '\n';
  }
  cout << endl;
  return 0;
}