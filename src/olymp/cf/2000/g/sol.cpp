#include <bits/stdc++.h>

using namespace std;

struct S {
  int u, v;
  int l1, l2;
};

int solve(int t0, int t1, int t2, int n, int m, vector<S> &ss) {
  int res = -1;
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int t0, t1, t2;
    cin >> t0 >> t1 >> t2;
    vector<S> ss(m);
    for (int i = 0; i < m; ++i) {
      cin >> ss[i].u >> ss[i].v >> ss[i].l1 >> ss[i].l2;
    }
    cout << solve(t0, t1, t2, n, m, ss) << '\n';
  }  
  cout << endl;
  return 0;
}