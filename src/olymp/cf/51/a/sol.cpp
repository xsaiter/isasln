#include <bits/stdc++.h>

using namespace std;

using D = vector<int>;

D turn(const D &d) {
  D r(4);
  r[1] = d[0];
  r[3] = d[1];
  r[0] = d[2];
  r[2] = d[3];
  return r;
}

bool eq(const D &l, const D &r) {
  for (int i = 0; i < 4; ++i) {
    if (l[i] != r[i]) {
      return false;
    }
  }
  return true;
}

bool operator==(const D &l, const D &r) {
  if (eq(l, r)) {
    return true;
  }
  auto x = l;
  for (int i = 0; i < 3; ++i) {
    x = turn(x);
    if (eq(x, r)) {
      return true;
    }
  }
  return false;
}

struct D_cmp {
  bool operator()(const D &l, const D &r) const { return l == r; }
};

struct D_hash {
  size_t operator()(const D &d) const { return d[0] ^ d[1] ^ d[2] ^ d[3]; }
};

int solve(vector<D> &dd, int n) {
  unordered_set<D, D_hash, D_cmp> s(begin(dd), end(dd));
  return (int)s.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<D> dd(n);
  auto Fi = [](int x) { return (x - (x % 10)) / 10; };
  auto Se = [](int x) { return x % 10; };
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    D d(4);
    d[0] = Fi(t);
    d[1] = Se(t);
    cin >> t;
    d[2] = Fi(t);
    d[3] = Se(t);
    dd[i] = d;
    string s;
    cin >> s;
  }
  cout << solve(dd, n) << endl;
  return 0;
}