#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a, vector<int> &b, int l, int r) {
  
}

int main() {
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << solve(n, a, b, l, r) << ' ';
    }    
    cout << '\n';
  }
  cout << endl;
  return 0;
}