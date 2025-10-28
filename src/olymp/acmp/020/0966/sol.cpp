#include <bits/stdc++.h>

using namespace std;

struct R {
  int l, r, v;
};

struct W {
  int id, t, v;  
  bool beg;
  bool is_active;
};

bool cmp_w(const W &x, const W &y) {
  return x.t < y.t;
}

vector<W> create_b(int n, const vector<R> &a) {
  vector<W> b;
  for (int i = 0; i < n; ++i) {
    W p;
    p.id = i;
    p.t = a[i].l;    
    p.v = a[i].v;
    p.beg = true;
    p.is_active = true;
    b.push_back(p);

    W q;
    q.id = i;
    q.t = a[i].r;    
    q.v = a[i].v;
    q.beg = false;
    q.is_active = true;
    b.push_back(q);
  }  
  sort(begin(b), end(b), cmp_w);  
  return b;
}

int solve(int n, const vector<R> &a, int t) {
  int k = 2 * n;
  vector<W> b = create_b(n, a);  
  int ans = 0;
  vector<W> acts;  
  for (int i = 0; i < k; ++i) {
    int m = (int)b.size();
    for (int j = 0; j < m; ++j) {
      int dt = b[i].t - acts[j].t;
      ans += dt * acts[j].v;
    }
    if (b[i].beg) {
      acts.push_back(b[i]);
    } else {
      for (int j = 0; j < m; ++j) {        
      }
    }    
  }
  return ans;
}

int main() {
  int n; cin >> n;
  vector<R> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].l >> a[i].r >> a[i].v;
  }
  int t; cin >> t;
  cout << solve(n, a, t) << endl;
  return 0;
}