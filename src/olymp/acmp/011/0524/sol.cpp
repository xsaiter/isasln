#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

struct R {
  int n;
  P c;
};

R solve(const P &a, const P &b) {
  R r;
  return r;
}

int main() {
  P a, b;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  R r = solve(a, b);
  cout << r.n;
  if (r.n == 2) {    
    cout << '\n' << r.c.x << ' ' << r.c.y;
  }
  cout << endl;
  return 0;
}