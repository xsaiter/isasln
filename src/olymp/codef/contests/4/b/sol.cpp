#include <bits/stdc++.h>

using namespace std;

struct A {
  int p, q;
};

struct R {
  bool can;
  vector<int> b;  
};

R yes_r(const vector<int> &b) {
  return R { .can = true, .b = b };
}

R no_r() {
  return R { .can = false };
}

R solve(int n, int m, vector<A> &a) {  
  int mi = 0, ma = 0;
  for (int i = 0; i < n; ++i) {
    mi += a[i].p;
    ma += a[i].q;
  }
  if (m < mi || ma < m) {
    return no_r();
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = a[i].p;
  }
  int rem = m - mi;
  for (int i = 0; i < n; ++i) {
    if (rem > 0) {
      int add = min(rem, a[i].q - a[i].p);
      b[i] += add;
      rem -= add;
    }        
  }
  return yes_r(b);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<A> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].p >> a[i].q;
  }
  R r = solve(n, m, a);
  if (r.can) {
    cout << "YES\n";
    for (int i =0 ; i <n; ++i) {
      cout << r.b[i] << ' ';
    }
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}