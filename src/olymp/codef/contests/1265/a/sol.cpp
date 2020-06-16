#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int gen(int x, int y) {
  while (x == y) {
    if (++x > 2) {
      x = 0;
    }
  }  
  return x;
}

int gen(int x, int y, int z) {
  while (x == y || x == z) {
    if (++x > 2) {
      x = 0;
    }
  }
  return x;
}

pair<string, bool> solve(const string &s) {
  int n = (int)s.size();
  vector<char> r(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] != '?') {      
      if (i > 0) {
        if (s[i] == s[i - 1]) {
          return {"", false};
        }
      }
      r[i] = s[i];
    } else {      
      char c = 'a';
      if (n > 1) {        
        int x = c - 'a';
        if (i == 0) { // first
          if (s[i + 1] != '?') {            
            int nx = s[i + 1] - 'a';
            c = 'a' + gen(x, nx);
          }                    
        } else if (i < n - 1) { // middle
          if (s[i + 1] != '?') {            
            int nx = s[i + 1] - 'a';          
            int px = r[i - 1] - 'a';
            c = 'a' + gen(x, nx, px);
          } else {
            int nx = r[i - 1] - 'a';
            c = 'a' + gen(x, nx);
          }
        } else { // last          
          int nx = r[i - 1] - 'a';
          c = 'a' + gen(x, nx);
        }
      }
      r[i] = c;      
    }
  }
  string res(r.begin(), r.end());
  return {res, true};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    auto res = solve(s);
    if (res.se) {
      cout << res.fi;
    } else {
      cout << "-1";
    }
    cout << "\n";
  }
  cout << endl;
  return 0;
}