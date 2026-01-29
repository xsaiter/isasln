#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct R {
  int k;
  int p, q;
};

R new_r(int k, int p, int q) {
  return R { .k = k, .p = p, .q = q };
}

void solve(int n, vector<int> &a, int &l, int &r) {  
  unordered_map<int, R> m;  
  for (int i = 0; i < n; ++i) {
    auto it = m.find(a[i]);
    if (it != m.end()) {
      (it->second).q = i;
      (it->second).k += 1;
    } else {
      m.insert({a[i], new_r(1, i, i)});
    }
  }  
  int max_k = -1; 
  int min_dist = INF;
  for (const auto &x : m) {
    auto v = x.second;    
    if (max_k == v.k) {      
      if (min_dist > v.q - v.p) {
        min_dist = v.q - v.p;
        l = v.p;
        r = v.q;
      }
    } else if (max_k < v.k) {
      max_k = v.k;       
      min_dist = v.q - v.p;
      l = v.p;
      r = v.q;
    }
  }    
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int l = 0, r = 0;
  solve(n, a, l, r);
  ++l; ++r;
  cout << l << ' ' << r << endl;  
  return 0;
}