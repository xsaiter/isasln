#include <bits/stdc++.h>

using namespace std;

struct Q {
  int l, r;
};

struct S {
  int n;
  vector<int> pref;
  vector<int> suff;
  int query(const Q &q) const {
    if (q.l == q.r) {
      return 0;
    }    
    return gcd(pref[q.r - 1], suff[q.l]);    
  }
};

int query(int n, const vector<int> &a, int l, int r) {
  if (l == r) {
    return 0;
  }
  int d = abs(a[l + 1] - a[l]);    
  for (int i = l + 2; i <= r; ++i) {    
    int diff = abs(a[i] - a[i - 1]);    
    d = gcd(d, diff);
  }
  return d;
}

S make_s(int n, const vector<int> &a) { 
  vector<int> pref(n);
  pref[0] = 0;
  for (int i = 1; i < n; ++i) {
    pref[i] = gcd(pref[i - 1], abs(a[i] - a[i - 1]));
  }
  vector<int> suff(n);
  suff[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    suff[i] = gcd(suff[i + 1], abs(a[i + 1] - a[i]));
  }
  return S { .n = n, .pref = pref, .suff = suff };
}

Q read_q() {
  Q q;
  cin >> q.l >> q.r;
  q.l--; q.r--;
  return q;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    S s = make_s(n, a);       
    for (int i = 0; i < m; ++i) {
      Q q = read_q();      
      cout << s.query(q) << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}