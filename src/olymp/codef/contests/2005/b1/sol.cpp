#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, int m, int q, vector<int> &b, vector<int> &a) {
  vector<int> r(q);
  return r;
}

int main() {
  int t;
  while (t--) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    vector<int> a(q);
    for (int i = 0; i <q; ++i) {
      cin >> a[i];
    }
    vector<int> r = solve(n, m, q, b, a);
    for (int i = 0 ; i < q; ++i) {
      cout << r[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}