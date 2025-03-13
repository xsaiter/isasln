#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<int> &a) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int j = i + 1;    
    if (j % 2 == 0) {
      res -= a[i];
    } else {
      res += a[i];
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}