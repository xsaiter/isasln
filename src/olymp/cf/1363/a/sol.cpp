#include <bits/stdc++.h>

using namespace std;

int a[2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    int e;
    a[0] = a[1] = 0;    
    for (int i = 0; i < n; ++i) {
      cin >> e;
      ++a[e % 2];
    }      
    int r = false;
    for (int i = 1; i <= a[1]; i += 2) {
      if (x - i < 0) {
        break;
      }
      if (x - i <= a[0]) {
        r = true;
        break;
      }
    }
    cout << (r ? "yes" : "no") << "\n";
  }
  cout << endl;
  return 0;
}