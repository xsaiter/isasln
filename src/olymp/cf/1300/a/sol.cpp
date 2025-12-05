#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int z = 0;
    int s = 0;    
    for (int i = 0; i < n; ++i) {
      s += a[i];
      if (a[i] == 0) ++z;      
    }
    int r = 0;
    if (z > 0) {
      if (-s == z) {
        r = z; ++r;
      } else {
        r = z;
      }
    } else {
      if (s == 0) {
        r = 1;
      }
    }
    cout << r << '\n';
  }
  cout << endl;
  return 0;
}