#include <bits/stdc++.h>

using namespace std;

struct R {
  bool ok;  
  vector<int> a;
};

R new_r_ok(const vector<int> &a) {
  return R {.ok = true, .a = a};
}

R new_r_fail() {
  return R {.ok = false};
}

vector<int> only_c(int n, const string &s, char c) {
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    if (s[i] == c) {
      a.push_back(i);
    }
  }
  return a;
}

R solve(int n, string &s) {  
  vector<int> a_0 = only_c(n, s, '0');
  vector<int> a_1 = only_c(n, s, '1');
  if (!a_0.empty()) {
    return new_r_ok(a_0);
  }
  if (!a_1.empty()) {
    return new_r_ok(a_1);
  }
  return new_r_fail();
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;    
    R res = solve(n, s);
    if (res.ok) {
      int m = (int)res.a.size();
      cout << m << '\n';
      for (int i = 0; i < m; ++i) {
        cout << res.a[i] + 1 << ' ';
      }            
    } else {
      cout << -1;
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}