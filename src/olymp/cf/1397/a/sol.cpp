#include <bits/stdc++.h>

using namespace std;

bool solve(vector<string> &v, int n) {
  vector<char> a;
  for (int i = 0; i < n; ++i) {
    int k = (int)v[i].size();
    for (int j = 0; j < k; ++j) {
      a.push_back(v[i][j]);
    }
  }
  int m = (int)a.size();
  if (m % n != 0) return false;
  sort(begin(a), end(a));
  char c = a[0];
  int x = 1;
  for (int i = 1; i < m; ++i) {
    if (c == a[i]) {
      ++x;
    } else {
      if (x % n != 0) return false;
      x = 1;
      c = a[i];
    }
  }
  if (x > 0) {
    if (x % n != 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];       
    }    
    cout << (solve(v, n) ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}