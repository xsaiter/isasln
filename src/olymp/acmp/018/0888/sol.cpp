#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  int ans = 0, cur = 0;
  if (a[0] == 1) {
    cur = 3;
  }
  ans += cur;
  for (int i = 1; i < n; ++i) {
    if (a[i] == 1) {
      ans += 1;
    } else {
      ans +=
    }
  }
  return ans;
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