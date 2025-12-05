#include <bits/stdc++.h>

using namespace std;

struct E {
  int u, v;
};

int solve(int n, int k, vector<E> &ee) {
  int res = 0;
  return res;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<E> ee(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      cin >> ee[i].u >> ee[i].v;
    }
    cout << solve(n, k, ee) << '\n';
  }
  cout << endl;
  return 0;
}