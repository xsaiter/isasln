#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int n, int k) {
  int res = 0;
  int l = 0, r = n - 1;
  while (l <= r) {
    if (a[l] <= k) {
      ++res;
      ++l;
    } else if (a[r] <= k) {
      ++res;
      --r;
    } else {
      break;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(a, n, k) << endl;
  return 0;
}