#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  int res = 0;
  vector<int> b(n, 0);
  for (int i = n - 1; i >= 0; --i) {    
    if (i + a[i] < n) {
      b[i] += a[i];
    }    
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << "\n";
  }
  cout << endl;
  return 0;
}