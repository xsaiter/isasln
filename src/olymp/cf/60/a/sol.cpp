#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using P = pair<int, int>;

struct Range {
  Range() {}
  Range(int l_, int r_) : l(l_), r(r_) {}
  int l, r;
  int len() const { return r - l; }
};

bool operator==(const Range &a, const Range &b) {
  return a.l == b.l && a.r == b.r;
}

bool operator!=(const Range &a, const Range &b) { return !(a == b); }

bool is_intersect(const Range &a, const Range &b) {
  return (a.l >= b.l && a.l <= b.r) || (b.l >= a.l && b.l <= a.r);
}

Range merge_intersect_ranges(const Range &a, const Range &b) {
  if (a.l < b.l) {
    return a.r < b.r ? Range(a.l, b.r) : Range(a.l, a.r);
  }
  return a.r < b.r ? Range(b.l, b.r) : Range(b.l, a.r);
}

int solve(const vector<P> &pp, int n) {
  int res = 0;
  vector<int> v(n, 0);
  Range x(1, n);
  for (auto &p : pp) {
    Range y;
    if (p.fi == -1) {
      y.l = 1;
      y.r = p.se;
    } else {
      y.l = p.se;
      y.r = n;
    }
    if (!is_intersect(x, y))
      return -1;
    x = merge_intersect_ranges(x, y);
    if (x.len() == 1) {
      if (res == 0)
        return -1;
      else
        return res;
    }
    ++res;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<P> pp(m);
  cin >> ws;
  for (int i = 0; i < m; ++i) {
    string s;
    getline(cin, s);
    int a, b;
    if (s[7] == 'l')
      a = -1;
    else
      a = 1;
    int n = (int)s.size();
    int j = n;
    while (s[--j] != ' ') {
    }
    b = atoi(s.substr(j + 1, n - j + 1).c_str());
    pp[i] = {a, b};
  }
  cout << solve(pp, n) << endl;
  return 0;
}