#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

struct R {
  bool yes;
  int k;
};

int dist2(const P &a, const P &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

R solve(int n, const P &b, int l, vector<P> &a) {
  R r;
  r.yes = true;
  int l2 = l * l;
  for (int i = 0; i < n; ++i) {
    if (l2 >= dist2(a[i], b)) {
      r.yes = false;
      r.k = i + 1;
      break;
    }
  }
  return r;
}

int main() {
  int n;
  cin >> n;
  P b;
  cin >> b.x >> b.y;
  int l;
  cin >> l;
  vector<P> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  R r = solve(n, b, l, a);
  if (r.yes) {
    cout << "Yes";
  } else {
    cout << r.k;
  }
  cout << endl;
  return 0;
}