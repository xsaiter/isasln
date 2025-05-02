#include <bits/stdc++.h>

using namespace std;

struct R {
  int a, b;
};

R add(const R &x, const R &y) {
  return R { .a = x.a + y.a, .b = x.b + y.b};
}

bool solve(int k, int w, vector<R> &t) {
  vector<R> r(7);
  r[0] = add(t[0], t[1]);
  r[1] = add(t[0], t[2]);
  r[2] = add(t[1], t[2]);
  r[3] = add(r[0], t[2]);
  r[4] = t[0];
  r[5] = t[1];
  r[6] = t[2];
  for (int i = 0; i < 7; ++i) {
    if (r[i].a <= w && r[i].b >= k) {
      return true;
    }
  }
  return false;
}

int main() {
  int k, w;
  cin >> k >> w;  
  vector<R> t(3);
  for (int i = 0; i < 3; ++i) {
    cin >> t[i].a >> t[i].b;
  }
  cout << (solve(k, w, t) ? "YES" : "NO") << endl;
  return 0;
}