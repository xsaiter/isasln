#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, vector<int> &b, int n, int k) { 
  sort(begin(a), end(a));
  sort(begin(b), end(b), greater<int>());
  if (k > 0) {
    for (int i = 0; i < n; ++i) {
      if (a[i] < b[i]) {
        a[i] = b[i];
        --k;
      }
      if (k == 0) break;
    }
  }  
  return accumulate(begin(a), end(a), 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cout << solve(a, b, n, k) << "\n";
  }
  cout << endl;
  return 0;
}