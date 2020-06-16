#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

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
      char c;
      if (i > 0) {
        if (r[i - 1] == 'a') {
          c = 'b';
        } else if (r[i - 1] == 'b') {
          c = 'c';
        } else if (r[i - 1] == 'c') {
          c = 'a';
        }
      } else {
        c = 'a';
      }
      if (i < n - 1) {
        if (s[i + 1] == c) {
          int x = (int)c - (int)'a';
          char cand;
          if (i == 0) {
            cand = (char)((int)'a' + (2 - x));
          } else {
            int px = (int)r[i - 1] - (int)'a';
            cand = (char)((int)'a' + (3 - (x + px)));
          }          
          if (c == cand && r[i - 1] == cand) {
            return {"", false};
          }
          c = cand;
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