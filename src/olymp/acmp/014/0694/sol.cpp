#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct P {
  int l, r;
};

// 2->10  5->12  11->20
bool solve(int n, vector<P> &a) {  
  int l = a[0].l, r = a[0].r;
  for (int i = 1; i < n; ++i) {
    l = max(l, a[i].l);
    r = min(r, a[i].r);
  }
  return l <= r;
}

int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  for (int i =0 ; i < n; ++i) {
    cin >> a[i].l >> a[i].r;
  }
  cout << (solve(n, a) ? "YES" : "NO") << endl;
  return 0;
}