#include <bits/stdc++.h>

using namespace std;

using LL = long long;

LL solve(int n, vector<LL> &a) {    
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return a[1] - a[0];
  }
  
  LL res = LLONG_MAX;    
  LL best = 1, d = 0  ;
  for (int i = 1; i < n; i += 2) {
    d = a[i] - a[i - 1];
    best = max(best, d);
  }
  res = min(res, best);

  if (n % 2 == 0) {
    return res;
  }
  
  best = 1;
  for (int i = 2; i < n; i += 2) {
    d = a[i] - a[i - 1];
    best = max(best, d);
  }
  res = min(res, best);

  best = 1;
  for (int i = 1; i < n - 1; i += 2) {
    d = a[i] - a[i - 1];
    best = max(best, d);
  }
  res = min(res, best);
  return res;
}

// 2 4 9
// 1 5 8 10 13
// 1 2 3 5 -> result = 2
// 1 2 4 5 -> result = 1

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}