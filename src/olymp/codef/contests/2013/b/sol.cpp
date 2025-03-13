#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n, vector<L> &a) {
  if (n == 2) {
    return a[1] - a[0];
  }  
  for (int i = n - 2; i >= 1; --i) {
    a[i - 1] = a[i] - a[i - 1];
  }
  return a[n - 1] - a[0];  
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<L> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}