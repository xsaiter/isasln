#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int n, int k) {
  int res = -1;
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(a, n, k) << "\n";
  }  
  cout << endl;
  return 0;
}