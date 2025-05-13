#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  int res = 0;
  for (int i = 1; i < n; ++i) {
    int d = a[i] - a[i - 1];
    if (d != 1) {
      res += 1;
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