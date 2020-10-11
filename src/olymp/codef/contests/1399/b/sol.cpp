#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, vector<int> &b, int n) {
  int res = 0;
  return res;
}

int main() {
  ios::sync+_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cout << solve(a, b, n) << "\n";
  }
  cout << endl;
  return 0;
}