#include <bits/stdc++.h>

using namespace std;
using L = long long;

// k, k + 1, .., k + n - 1
// i so min of x = |a1 + a2 + .. + ai - a[i+1] - ... - a[n]|

const L K = 3L;

L calc(L k, L i, L s) {
  L t = (k + k + i - 1L) * i / 2L;
  return abs(2L * t - s);
}

vector<L> search(L k, L l, L r, L s) {
  if (r - l < K) {
    vector<L> res;   
    for (L i = l; i <= r; ++i) {
      res.push_back(i);
    }    
    return res;
  }  
  L d = r - l;
  L rem = d % K;
  L m1 = l + (d - rem) / K + rem;
  L m2 = r - (d - rem) / K;   
  if (calc(k, m1, s) < calc(k, m2, s)) {
    return search(k, l, m2, s);
  }
  return search(k, m1, r, s);
}

L solve(L n, L k) {  
  L s = (k + k + n - 1L) * n / 2L;  
  vector<L> a = search(k, 1, n, s);
  int m = (int)a.size();
  L res = LLONG_MAX;
  for (int i = 0; i < m; ++i) {
    res = min(res, calc(k, a[i], s));
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >>  n >> k;
    cout << solve(n, k) << '\n';
  }
  cout << endl;
  return 0;
}