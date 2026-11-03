#include <bits/stdc++.h>

using namespace std;

bool solve(int n, vector<int> &w, int m, vector<int> &a) {
  
  return false;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i = 0 ; i < n; ++i) {
      cin >> w[i];
    }
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
      cin >> a[i];
    }
    cout << (solve(n,w, m, a) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}