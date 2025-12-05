#include <bits/stdc++.h>

using namespace std;

struct S {
  int w, h;

  bool is_valid(const S &x) const {
    return w > x.w && h > x.h;
  }
};

struct E {
  int w, h, j;  
};

vector<int> solve(int n, const S &x, const vector<S> &a) {
  vector<int> r;
  vector<E> b;
  for (int i = 0; i < n; ++i) {
    if (a[i].is_valid(x)) {
      E e { .w = a[i].w, .h = a[i].h, .j = i + 1 };
      b.push_back(e);      
    }
  }
  auto cmp_b = [](const E &l, const E &r) {
    if (l.w == r.w) {
      return l.h < r.h;
    }
    return l.w < r.w;
  };
  sort(begin(b), end(b), cmp_b);
  int m = (int)b.size();  
  if (m == 0) {
    return r;
  }
  vector<int> dp(m, 1);
  vector<int> di(m, -1);
  dp[0] = 1;
  for (int k = 0; k < m; ++k) {    
    for (int i = 0; i < k; ++i) {
      int v = dp[i] + 1;
      if (b[i].w < b[k].w && b[i].h < b[k].h && v > dp[k]) {
        dp[k] = v;
        di[k] = i;
      }
    }
  }  
  int ans = -1, pos = -1;
  for (int i = 0; i < m; ++i) {
    if (dp[i] > ans) {
      ans = dp[i];
      pos = i;
    }
  }  
  while (pos != -1) {
    r.push_back(b[pos].j);
    pos = di[pos];
  }  
  reverse(r.begin(), r.end());
  return r;
}

int main() {
  int n;
  cin >> n;
  S x;
  cin >> x.w >> x.h;
  vector<S> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].w >> a[i].h;
  }
  vector<int> r = solve(n, x, a);
  int nr = (int)r.size();
  cout << nr << '\n';
  for (int i = 0; i < nr; ++i) {
    cout << r[i] << ' ';
  }
  cout << endl;
  return 0;
}