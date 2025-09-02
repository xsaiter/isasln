#include <bits/stdc++.h>

using namespace std;

struct A {
  double v;
  string name;
  bool is_near() const {
    return name == "closer";
  }
  bool is_far() const {
    return name == "further";
  }
};

struct R {
  double p, q;
};

R solve(int n, vector<A> &a) {
  int p = 0, q = 4000;
  for (int i = 1; i < n; ++i) {
    p = min(p, a[i].v);
    q = max(q, a[i].v);
  }
  return R { .p = p, .q = q };
}

int main() {
  int n;
  cin >> n;
  vector<A> a(n);
  cin >> a[0].v; a[0].name = "";
  for (int i = 1; i < n; ++i) {
    cin >> a[i].v >> a[i].name;
  }
  R r = solve(n, a);
  printf("%f.6 %f.6", r.p, r.q);
  return 0;
}