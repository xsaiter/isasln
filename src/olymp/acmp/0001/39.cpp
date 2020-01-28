#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  auto m = begin(a);
  auto t = m;
  auto e = end(a);
  int pos = 1;
  while (m != e) {
    t = m;
    m = max_element(m, e);
    if (m != e) {
      pos += distance(t, m);
      res += (*m) * pos;
      m = next(m);
    }
  }
  cout << res << endl;
  return 0;
}