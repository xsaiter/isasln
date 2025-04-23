#include <bits/stdc++.h>

using namespace std;
using L = long long;

L solve(int n, int k, int x, vector<int> &a) {
  L res = 0L;
  
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {      
      cin >> a[i];
    }
    cout << solve(n, k, x, a) << '\n';
  }
  cout << endl;
  return 0;
}