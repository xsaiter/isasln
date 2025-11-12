#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(L n, vector<L> &a) {  
  L mx = *max_element(begin(a), end(a));
  if (mx == 1) {
    mx = 2;
  } else {
    mx *= 2;
  }
  for (L x = 2; x <= mx; ++x) {
    for (L i = 0; i < n; ++i) {
      if (gcd(a[i], x) == 1) {
        return x;
      }
    }
  }
  return -1;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    L n;
    cin >> n;
    vector<L> a(n);
    for (L i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}