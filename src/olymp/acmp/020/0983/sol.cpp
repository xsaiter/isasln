#include <bits/stdc++.h>

using namespace std;

using L = long long;

struct A {
  L t, w;
};

struct C {
  L t, w;
  int k;
};

vector<L> solve(int n, const vector<A> &a) {  
  vector<C> c(n);
  for (int i = 0; i < n; ++i) {
    c[i].t = a[i].t;
    c[i].w = a[i].w;
    c[i].k = i;
  }
  sort(begin(c), end(c), 
    [](const C &l, const C &r) {
      return l.w < r.w;
    } 
  );
  vector<L> b(n);
  for (int i = 0; i < n; ++i) {
    L x = c[i].t * c[i].w;
    if (i > 0 && x < b[c[i - 1].k]) {
      x = b[c[i - 1].k];
    }
    b[c[i].k] = x;
  }
  return b;
}

int main() {
  int n;
  cin >> n;
  vector<A> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].t >> a[i].w;
  }
  vector<L> b = solve(n, a);
  for (int i = 0; i < n; ++i) {
    cout << b[i] << '\n';
  }                  
  cout << endl;
  return 0;
}

