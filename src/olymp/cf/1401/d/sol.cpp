#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> u(n - 1);
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      cin >> u[i] >> v[i];
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
      cin >> p[i];
    }
  }
  return 0;
}