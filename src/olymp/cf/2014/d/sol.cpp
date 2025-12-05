#include <bits/stdc++.h>

using namespace std;

struct P {
  int l, r;
};

P solve(int n, int d, int k, vector<P> &a) {
  P res;
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d, k;
    cin >> n >> d >> k;
    vector<P> a(k);
    for (int i = 0; i < k; ++i) {
      cin >> a[i].l >> a[i].r;
    }
    P res = solve(n, d, k, a);
    cout << res.l << " " << res.r << '\n';
  }
  cout << endl;
  return 0;
}