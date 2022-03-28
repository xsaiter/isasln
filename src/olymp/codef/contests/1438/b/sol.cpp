#include <bits/stdc++.h>

using namespace std;

bool solve(int n, vector<int> &b) {
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cout << (solve(n, b) ? "YES" : "NO") << 'n';
  }
  cout << endl;
  return 0;
}