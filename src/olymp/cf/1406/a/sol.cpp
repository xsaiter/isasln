#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  int m = 101;
  vector<int> b(m, 0);
  for (int i = 0; i < n; ++i) {
    b[a[i]]++;
  }  
  for (int i = 0; i < m; ++i) {
    if (b[i] == 0) {
      for (int j = 0; j < m; ++j) {
        if (b[j] == 0) {
          return i + j;
        }
      }
    } else {
      b[i]--;
    }
  }
  throw "ERR";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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