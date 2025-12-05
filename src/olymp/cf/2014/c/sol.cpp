#include <bits/stdc++.h>

using namespace std;

// (a1 + a2 + a3 + a4 + a5) / 5
// s + x

int solve(int n, vector<int> &a) {
  if (n < 3) {
    return -1;
  }
  int res = 0;
  int mx = -INT_MAX;
  int j = -1;
  long long s = 0;
  int x = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > mx) {
      j = i;
    }    
    s += a[i];
  }  
  s += x;
  a[j] += x;
  double med = s / n;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {    
    if (a[i] < med) {
      ++cnt;
    }
  }
  return x;
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