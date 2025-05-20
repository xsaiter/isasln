#include <bits/stdc++.h>

using namespace std;

struct R {
  double v;
  string name;
};

struct Res {
  double mi, ma;
};

Res solve(int n, vector<R> &a) {
}

int main() {
  int n;
  cin >> n;
  vector<R> a(n);
  cin >> a[0].v;
  for (int i = 1; i < n; ++i) {
    cin >> a[i].v >> a[i].name;
  }
  Res res = solve(n, a);
  printf("%f.6 %f.6", res.mi, res.ma);
  return 0;
}