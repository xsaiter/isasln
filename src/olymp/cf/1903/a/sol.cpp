#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int k, vector<int> &a) {
  if (n == 1) {
    return true;
  }
  if (k == 1) {    
    return is_sorted(begin(a), end(a));  
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(n, k, a) ? "YES" : "NO") << '\n';
  }                                          
  cout << endl;
  return 0;
}