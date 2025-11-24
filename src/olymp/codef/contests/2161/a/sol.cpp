#include <bits/stdc++.h>

using namespace std;

bool solve(int n, vector<string> &a) {
  bool ans = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c = a[i][j];
    }
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(n, a) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}