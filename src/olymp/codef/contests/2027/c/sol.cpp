#include <bits/stdc++.h>

using namespace std;

// 0 < i <= len(a) and a[i] = len(a) + 1 - i
// adding (i - 1) of 0 at the ending of array

int dp(int n, int len, vector<int> &a, vector<int> &idx) {
  int res = n;
  for (int i = 0; i < n; ++i) {
    if (a[i] == len + 1 - i) {      
      int add = i - 1;
      res = max(res + add, dp(n, len + add, a));
    }
  }
  return res;
}

int solve(int n, vector<int> &a) {
  vector<int> idx(n);
  return dp(n, n, a);
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
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}