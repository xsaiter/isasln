#include <bits/stdc++.h>

using namespace std;

int sum(const vector<int> &a, int n) {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res += a[i];
  } 
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, t;
  cin >> n >> k >> t;
  bool q = false;
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      a[i] = j;
      int s = sum(a, n);
      double x = (double)s * 100 / (double)(n * k);
      double y = (double)(s + 1) * 100 / (double)(n * k);      
      if (x <= t && t < y) { q = true; break; }      
    }
    if (q) break;    
    a[i] = k;
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}