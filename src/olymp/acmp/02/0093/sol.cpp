#include <bits/stdc++.h>

using namespace std;

int suspect(const string &s, int m, vector<string> &b) {
  int ans = 0;
  int len = (int)s.size();
  for (int i = 0; i < m; ++i) {
    if (len == (int)b[i].size()) {
      int err = 0;
      for (int j = 0; j < len; ++j) {
         if (s[j] != b[i][j]) {
           err += 1;
           if (err > 1) {
             break;
           }
         }
      }
      if (err == 1) {
        ans += 1;
      }
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<string> b(m);
  for (int i = 0; i < m; ++i) {
   cin >> b[i];
  }
  for (int i = 0; i < n; ++i) {
    int cnt = suspect(a[i], m, b);
    cout << cnt << ' ';
  }
  cout << endl;
  return 0;
}