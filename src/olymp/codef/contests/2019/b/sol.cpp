#include <bits/stdc++.h>

using namespace std;
using L = long long;

L calc(L a, L b) {
  if (a > b) {
    swap(a, b);
  }
  return b - a + 1;
}

vector<L> solve(int n, int q, vector<L> &x, vector<L> &k) {
  vector<L> rr(q);
  for (int ri = 0; ri < q; ++ri) {
     L r = 0;
     rr[ri] = r;
  }
  return rr;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<L> x(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }
    vector<L> k(q);
    for (int i = 0; i < q; ++i) {
      cin >> k[i];
    }
    auto r = solve(n, q, x, k);
    for (int i = 0; i < q; ++i) {
      cout << r[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}