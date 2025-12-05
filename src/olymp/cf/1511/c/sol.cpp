#include <bits/stdc++.h>

using namespace std;
using S = vector<int>;

int find_pos_and_rotate(S &a, int n, int x) {
  auto it_beg = begin(a);
  auto it_end = end(a);
  int f = find(it_beg, it_end, x) - it_beg;  
  rotate(it_beg, it_beg + f, it_beg + f + 1);    
  return f + 1;
}

S solve(S &a, S &t, int n, int q) {
  S res;
  for (int x : t) {
    int pos = find_pos_and_rotate(a, n, x);
    res.push_back(pos);
  }
  return res;
}

int main() {
  int n, q;
  cin >> n >> q;  
  S a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  S t(q);
  for (int i = 0; i < q; ++i) {
    cin >> t[i];
  }
  S res = solve(a, t, n, q);
  copy(begin(res), end(res), ostream_iterator<int>(cout, " "));
  return 0;
}