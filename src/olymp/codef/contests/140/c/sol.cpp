#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

struct S {
  int t[3];
};

vector<S> ss;

bool can(vector<pii> &v) {  
  int n = (int)v.size();
  if (n < 3 || v[2].se == 0) {
    return false;
  }
  S s;
  s.t[0] = v[0].fi; v[0].se--;
  s.t[1] = v[1].fi; v[1].se--;
  s.t[2] = v[2].fi; v[2].se--; 
  sort(begin(s.t), end(s.t), [](auto x, auto y) { return x > y; });
  ss.push_back(s);    
  for (int i = 0; i < 3; ++i) {
    if (n > 3 && v[i].se < v[3].se) {
      swap(v[i], v[3]);
      for (int j = 3; j < n - 1; ++j) {
        if (v[j].se < v[j + 1].se) {
          swap(v[j], v[j + 1]);
        } else {
          break;
        }
      }
    }
  }  
  return true;
}

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  sort(begin(r), end(r));
  vector<pii> v;
  v.push_back({r[0], 1});
  for (int i = 1; i < n; ++i) {
    if (r[i] == r[i - 1]) {
      v.back().se++;
    } else {
      v.push_back({r[i], 1});
    }
  }
  sort(begin(v), end(v), [](const auto &x, const auto &y) { return x.se > y.se; });
  while (can(v)) { }  
  cout << ss.size() << "\n";  
  for (auto &x : ss) {
    cout << x.t[0] << " " << x.t[1] << " " << x.t[2] << "\n";
  }
  cout << endl;
  return 0;
}