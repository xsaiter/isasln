#include <bits/stdc++.h>

using namespace std;

// (a1 + a2 + a3 + a4 + a5) / 5

int solve(int n, vector<int> &a) {
  int res = 0;
  int mx = -INT_MAX;
  int pos_mx = -1;
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > mx) {
      pos_mx = i;
    }    
    s += a[i];
  }  
  s += x;
  double med = s / n;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {    
    if (a[i] < med) {
      ++cnt;
    }
  }
  if (cnt > n / 2) {
    return true;
  }  
  return false;
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