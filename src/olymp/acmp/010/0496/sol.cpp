#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  if (n == 3) {
    return accumulate(begin(a), end(a), 0);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      res = max(res, a[0] + a[1] + a[n - 1]);
    } else if (i == n - 1) {
      res = max(res, a[i] + a[i - 1] + a[0]);
    } else {
      res = max(res, a[i] + a[i - 1] + a[i + 1]);
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}