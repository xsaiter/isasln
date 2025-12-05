#include <bits/stdc++.h>

using namespace std;

struct A {
  int t, p, j;  
};

int sum(const vector<int> &b, int p, int q) {
  return b[p] - b[q];
}

vector<int> build_prefix_sum(const vector<A> &a, int n) {
  vector<int> b(n);
  b[0] = a[0]
  for (int i = 1; i < n; ++i) {
     b[i] = b[i - 1] + a[i];
  }
  return b;
}

void solve(int n, int v, vector<A> &a) {    
  vector<A> b, c;  
  for (int i = 0; i < n; ++i) {
    if (a[i].t == 1) {          
      b.push_back(a[i]);
    } else {
      c.push_back(a[i]);
    }
  }
  auto a_cmp = [](const A &l, const A &r) {
    return l.t > r.t;
  };
  sort(b.begin(), b.end(), a_cmp);
  sort(c.begin(), c.end(), a_cmp);
  int nb = (int)b.size();
  int nc = (int)c.size();

  int nca = min(nc, (int)v / 2);
  for (int k = 0; k <= nca; ++i) {
  }
}

int main() {
  int n, v;
  cin >> n >> v;
  vector<A> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].t >> a[i].p;
    a[i].j = i + 1;
  }
  solve(n, v, a);  
  return 0;
}