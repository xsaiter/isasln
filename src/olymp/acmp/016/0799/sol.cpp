#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct R {
  int v, j;
};

bool hit(int x) {
  string s = to_string(x);
  return s.back() == '5';
}

int solve(int n, vector<int> &a) {  
  int mx = *max_element(a.begin(), a.end());
  set<int> wins;
  for (int i = 0; i < n; ++i) {   
    if (a[i] == mx) {
      wins.insert(i);
    }
  }
  if (wins.empty()) {
    return 0;
  }
  set<int> cc;
  for (int i = 0; i < n - 1; ++i) {
    if (hit(a[i]) && a[i] > a[i + 1]) {            
      if (wins.begin() != wins.end() && *wins.begin() < i) {
        cc.insert(i);        
      }      
    }
  }
  if (cc.empty()) {
    return 0;
  }  
  vector<R> b;
  for (int i = 0; i < n; ++i) {
    b.push_back(R {.v = a[i], .j = i}); 
  }
  sort(b.begin(), b.end(), 
    [](const R &l, const R &r) {
      return l.v > r.v;
  });
  auto Place = [&](int c) {
    int res = 1;
    for (int i = 0; i < n; ++i) {        
      if (b[i].v == a[c]) {
        break;
      }
      res += 1;
    }
    return res;
  };
  int ans = INF;
  for (const auto &c : cc) {
    ans = min(ans, Place(c));
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}