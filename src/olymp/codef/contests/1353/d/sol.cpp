#include <bits/stdc++.h>

#define fi first
#define se second
#define MP make_pair

using namespace std;
using P = pair<int, int>;

struct Cmp {
  bool operator()(const P &x, const P &y) const {
    return f(x, y);
  }

  bool f(const P &x, const P &y) const {
    auto lx = x.se - x.fi + 1;
    auto ly = y.se - y.fi + 1;
    return (lx == ly) ? (x.fi < y.fi) : (lx > ly);
  }
};

using PQ = priority_queue<P, vector<P>, Cmp>;

void solve(int n, vector<int> &a) {
  PQ pq;
  pq.push(MP(1, n));
  for (int i = 0; i < n; ++i) {
    auto s = pq.top();
    pq.pop();
    int x = 0;
    auto len = s.se - s.fi + 1;
    if (len % 2 != 0) {
      x = (s.se + s.fi) / 2;
    } else {
      x = (s.se + s.fi - 1) / 2;
    }
    a[x - 1] = i + 1;
    if (s.fi <= x - 1) pq.push(MP(s.fi, x - 1));
    if (x + 1 <= s.se) pq.push(MP(x + 1, s.se));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> res(n, 0);
    solve(n, res);
    copy(begin(res), end(res), ostream_iterator<int>(cout, " "));
    cout <<  "\n";
  }
  cout << endl;
  return 0;
}