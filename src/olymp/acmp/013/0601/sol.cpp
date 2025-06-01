#include <bits/stdc++.h>

using namespace std;

struct H {
  int u, v, c;
};

int solve(int n, int m, vector<H> &hh, int k, vector<int> &r) {
  int ans = -1;
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<H> hh(m);
  for (int i = 0; i < m; ++i) {
    cin >> hh[i].u >> hh[i].v >> hh[i].c;
  }
  int k;
  cin >> k;
  vector<int> r(k);
  for (int i = 0; i < k; ++i) {
    cin >> r[i];
  }
  int ans = solve(n, m, hh, k);
  if (ans == -1) {
    cout << "INCORRECT";
  } else {
    cout << ans;
  }
  cout << endl;
  return 0;
}