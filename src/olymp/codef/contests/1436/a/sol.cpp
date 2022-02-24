#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int m, vector<int> &a) {
  int s = accumulate(begin(a), end(a), 0);
  return s == m;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(n, m, a) == true ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}