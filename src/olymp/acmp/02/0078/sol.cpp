#include <bits/stdc++.h>

using namespace std;

struct R {
  int rem;
  int cnt;

  int back(int p) const {
    return rem + cnt * p;
  }
};

R front(int x, int f) {
  int rem = x % f;
  int cnt = (x - rem) / f;
  return R{ .rem = rem, .cnt = cnt };
}

int cx(int x, int f, int p) {
  R r = front(x, f);

  x = r.back(p);
  r = front(x, f);

  x = r.back(p);
  r = front(x, f);

  x = r.back(p);
  r = front(x, f);

  x = r.back(p);

  return x;
}

int solve(int f, int p) {
  int d = f - p;
  if (cx(f - 1, f, p) == f) {
    return f - 1;
  }
  if (cx(p, f, p) == f) {
    return p;
  }
  for (int i = f; i <= 1e9; i += d) {
    if (cx(i, f, p) == f) {
      return i;
    }
  }
  return 0;
}

int solve_eps(int f, int p) {
  for (int i = 1; i < 1e9; ++i) {
    if (cx(i, f, p) == f) {
      return i;
    }
  }
  return 0;
}

int main() {
  int f, p;
  cin >> f >> p;
  /*for (int i = 1; i <= 30; ++i) {
    cout << i << ' ' << cx(i, f, p) - f << endl;
  }*/
  cout << solve(f, p) << endl;
  cout << solve_eps(f, p) << endl;
  return 0;
}