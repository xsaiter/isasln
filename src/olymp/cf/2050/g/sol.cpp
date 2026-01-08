#include <bits/stdc++.h>

using namespace std;

struct E {
  int a, b;
};

int solve(int n, vector<E> &g) {
  int ans = 0;
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<E> g(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      cin >> g[i].a >> g[i].b;
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}