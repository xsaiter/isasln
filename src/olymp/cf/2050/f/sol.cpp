#include <bits/stdc++.h>

using namespace std;

struct Q {
  int l, r;
};

struct S {
  vector<int> b;

  int query(Q &q) const {
    int ans = 0;
    return ans;
  }
};

S make_s(int n, vector<int> &a) {
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    S s = make_s(n, a);
    int m;
    cin >> m;    
    for (int i = 0; i < m; ++i) {
      Q q;
      cin >> q.l >> q.r;
      cout << s.query(q) << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}