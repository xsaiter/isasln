#include <bits/stdc++.h>

using namespace std;

// 0 < i <= len(a) and a[i] = len(a) + 1 - i
// add (i - 1) 0 at the ending of array

int solve(int n, vector<int> &a) {
  int res = 0;
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