#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> &a, const vector<int> &b) {
  int res = 0;
  if (a[2] > b[0]) {
    res += 2 * b[0];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    vector<int> a(3);
    vector<int> b(3);
    for (int i = 0; i < 3; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < 3; ++i) {
      cin >> b[i];
    }
    cout << solve(a, b) << "\n";
  }
  cout << endl;
  return 0;
}