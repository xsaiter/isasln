#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a;
  cin >> n >> m >> a;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }
  return 0;
}