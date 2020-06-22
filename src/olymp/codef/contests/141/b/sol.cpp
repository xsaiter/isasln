#include <bits/stdc++.h>

using namespace std;

struct P { int x, y; };
struct R { P a, c; };

bool inside(const R &r, const P &p) {
  return r.a.x < p.x && r.a.y < p.y && r.c.x > p.x && r.c.y > p.y;
}

int solve(int a, int b, int c) {
  int res = -1;

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cit.tie(nullptr);
  int a, x, y;
  cin >> a >> x >> y;
  cout << solve(a, b, c) << endl;
  return 0;
}