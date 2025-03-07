#include <bits/stdc++.h>

using namespace std;

int mex(const vector<int> &a, int n, int k) {  
  sort(begin(a), end(a));
  int res = -1;
  for (int i = 1; i < n; ++i) {
  }
  return res;
}

// a[i] >= a[j]
// a[i] = a[i] - a[j]
// a[i] = a[i] + a[j]

int solve(int n, int k, vector<int> &a) {
  int res = 0;
  return res;
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
    cout << solve(n, k, a) << '\n';
  }
  cout << endl;
  return 0;
}