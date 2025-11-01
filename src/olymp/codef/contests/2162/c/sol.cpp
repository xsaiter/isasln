#include <bits/stdc++.h>

using namespace std;

struct R {
  bool yes;
  vector<int> v;
};

R r_no() {
  return R {.yes = false};
}

R r_yes(const vector<int> &v) {
  return R {.yes = true, .v = v};
}

R solve(int a, int b) {
  if (__builtin_clz(a) > __builtin_clz(b)) {
    return r_no();
  }
  vector<int> v;
  if (a == b) {
    return r_yes(v);
  }  
  for (int i = 0; i < 31; ++i) {
    int x = (1 << i);
    if (x <= a && (a & x) == 0) {
      a += x; 
      v.push_back(x);
    }
  }
  for (int i = 0; i < 31; ++i) {
    int x = (1 << i);
    if (x <= a && (b & x) == 0) {
      v.push_back(x);
    }
  }
  return r_yes(v);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    R r = solve(a, b);
    if (r.yes) {
      int m = (int)r.v.size();
      cout << m;
      if (m > 0) {
        cout << '\n';
      }
      for (int i = 0; i < m; ++i) {
        cout << r.v[i] << ' ';
      }
    } else {
      cout << -1;
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}