#include <bits/stdc++.h>

using namespace std;

bool solve(string &a, string &b, string &c) {
  int n = (int)a.size();
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      if (a[i] != c[i]) return false;
    } else {
      if (a[i] != c[i] && b[i] != c[i]) return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a >> b >>c ;
    cout << (solve(a, b, c) ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}