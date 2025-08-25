#include <bits/stdc++.h>

using namespace std;

struct R {
  int v, d;
  
  bool operator<(const R &other) const {
    return v < other.v;
  }

  bool operator==(const R &other) const {
    return v == other.v;
  }
};

template<typename T> int len(const vector<T> &a) {
  return (int)a.size();
}

vector<int> factors(int n) {
  vector<int> a;
  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      a.push_back(i);
      n /= i;
    }
  }
  if (n > 1) {
    a.push_back(n);
  }
  a.push_back(1);
  sort(begin(a), end(a));    
  return a;
}

set<R> factors_r(int n) {
  set<R> res;  
  if (n == 1) {        
    res.insert(R {.v = 1, .d = 1});
    return res;
  } 
  vector<int> a = factors(n);
  R r {.v = a[0], .d = 1};
  int na = len(a);
  for (int i = 1; i < na; ++i) {
    if (a[i] == r.v) {
      r.d += 1;
    } else {
      res.insert(r);
      r.v = a[i]; 
      r.d = 1;
    }
  }
  res.insert(r);
  return res;
}

int solve(int n, int m) {
  if (n == m) {
    return 0;
  }  
  set<R> a = factors_r(n);
  set<R> b = factors_r(m);  
  int res = 0;  
  for (const auto &x : a) {    
    auto it = b.find(x);
    if (it != b.end()) {
      res += abs(x.d - (*it).d);
    } else {
      res += x.d;
    }    
  }
  for (const auto &x : b) {
    if (!a.contains(x)) {
      res += x.d;
    }
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;  
  cout << solve(n, m) << endl;  
  return 0;
}