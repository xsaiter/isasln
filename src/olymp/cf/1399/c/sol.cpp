#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &w, int n) {
  int res = 0;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0 ; i < n; ++i) {
      cin >> w[i];
    }
    cout << solve(w, n) << "\n";
  }
  cout << endl;
  return 0;
}