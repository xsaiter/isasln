#include <bits/stdc++.h>

using namespace std;
using L = long long;

const int K = 3;

struct Res {
  int m, k;
};

int calc(int n, const vector<int> &a, int v) {
  int res = -INT_MAX;
  for (int i = 1; i < n; ++i) {
    int r = a[i];
    int l = a[i - 1];
    if (r == -1) {
      r = v;
    }
    if (l == -1) {
      l = v;
    }
    res = max(res, abs(r - l));
  }
  return res;
}

vector<int> search(int n, const vector<int> &a, int l, int r) {
  if (r - l < K) {
    vector<int> res;
    for (int i = l; i <= r; ++i) {
      res.push_back(i);
    }
    return res;
  }
  int d = r - l;
  int rem = d % K;
  int m1 = l + (d - rem) / K + rem;
  int m2 = r - (d - rem) / K;   
  if (calc(n, a, m1) < calc(n, a, m2)) {
    return search(n, a, l, m2);
  }
  return search(n, a, m1, r);
}

Res solve(int n, const vector<int> &a) {
  int max_value = *max_element(begin(a), end(a));
  vector<int> v = search(n, a, 0, max_value + 1);
  int nv = (int)v.size();
  int md = INT_MAX;
  int mk = 0;
  for (int i = 0; i < nv; ++i) {
    L d = calc(n, a, v[i]);
    if (d < md) {
      md = d;
      mk = v[i];
    }    
  }
  return Res { .m = md, .k = mk };
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
    Res res = solve(n, a);
    cout << res.m << " " << res.k << '\n';
  }
  cout << endl;
  return 0;
}