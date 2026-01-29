#include <bits/stdc++.h>

using namespace std;

using L = long long;

struct R {
  int x;
  L k;
};

struct Seg {
  vector<R> b;

  void init(bool is_left) {
    if (is_left) {
      sort(b.begin(), b.end(), [](const R &l, const R &r) { return l.x > r.x; });
    } else {
      sort(b.begin(), b.end(), [](const R &l, const R &r) { return l.x < r.x; });
    }
  }
  
  int len() const {
    return (int)b.size();
  }

  L sum() const {
    return sum(0, len());
  }

  L sum(int p, int q) const {
    L res = 0LL;
    for (int i = p; i < q; ++i) {
      res += b[i].k;
    }
    return res;
  }  
};

L solve(int n, vector<R> &a) {  
  Seg l, r;
  for (int i = 0; i < n; ++i) {
    if (a[i].x < 0) {
      l.b.push_back(a[i]);
    } else {
      r.b.push_back(a[i]);
    }
  }
  l.init(true); r.init(false);      
  if (l.len() < r.len()) {    
    return l.sum() + r.sum(0, l.len() + 1);    
  } else if (l.len() > r.len()) {
    return r.sum() + l.sum(0, r.len() + 1);    
  }
  return l.sum() + r.sum();
}

int main() {
  int n;
  cin >> n;
  vector<R> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].k;
  }  
  cout << solve(n, a) << endl;
  return 0;
}