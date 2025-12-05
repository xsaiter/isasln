#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  int m = 101;
  vector<int> c(m);
  for (int i = 0; i < n; ++i) {
    c[a[i]] += 1;
  }
  for (int i = 0; i < m; ++i) {
    if (c[i] == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  int tt;
  cin >> tt;  
  while (tt--) {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}