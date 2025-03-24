#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a, string &s) {
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
    string s;
    cin >> s;
    cout << solve(n, a, s) << '\n';
  }
  cout << endl;
  return 0;
}
