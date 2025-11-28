#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<int> c;
  set_intersection(
    a.begin(), a.end(),
    b.begin(), b.end(),
    back_inserter(c));

  sort(c.begin(), c.end());
  auto ptr = unique(c.begin(), c.end());
  c.erase(ptr, c.end());

  for (const auto &x : c) {
    cout << x << ' ';
  }
  
  cout << endl;
  return 0;
}