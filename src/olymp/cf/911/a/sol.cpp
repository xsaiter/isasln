#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int mi = 0;
  int m = 1e9 + 1;
  int res = 1e5 + 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] < m) {
      m = a[i];
      mi = i;
      res = 1e5 + 1;          
    } else if (a[i] == m) {      
      int d = abs(i - mi);
      if (d < res) {        
        res = d;
      }
      mi = i;
    }
  }
  cout << res << endl;
  return 0;
}