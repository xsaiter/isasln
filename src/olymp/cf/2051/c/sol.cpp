#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
      cin >> a[i];
    }
    vector<int> q(k);
    for (int i = 0; i < k; ++i) {
      cin >> q[i];
    }        
    vector<int> known(n + 1, 0);
    for (int i = 0; i < k; ++i) {
      known[q[i]] = 1;
    }
    for (int i = 0; i < m; ++i) {      
      int yes = 0;
      if (n - k == 1) {
        if (known[a[i]] == 0) {
          yes = 1;
        }
      } else if (n - k == 0) {
        yes = 1;
      }     
      cout << yes;
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}