#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    string s(m, 'B');    
    for (int i = 0; i < n; ++i) {
      int j = a[i] - 1;
      int k = m + 1 - a[i] - 1;
      int mi = min(j, k);
      int ma = max(j, k);
      if (s[mi] == 'B') {
        s[mi] = 'A';
      } else {
        s[ma] = 'A';
      }
    }
    cout << s << '\n';
  }
  cout << endl;
  return 0;
}