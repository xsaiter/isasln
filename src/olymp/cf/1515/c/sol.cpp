#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &h, int n, int m, int x, vector<int> &res) {
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
    }
    vector<int> res;
    bool can = solve(h, n, m, x, res);
    if (can) {
      cout << "YES" << '\n';
      copy(begin(res), end(res), ostream_iterator<int>(cout, ' '));
      cout << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}