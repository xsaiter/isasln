#include <bits/stdc++.h>

using namespace std;

struct Res {  
  bool yes;
  string s;
};

const int NO_POS = -1;

Res solve(string &t) {  
  int n = (int)t.size();
  int kk = (n - (n % 2)) / 2;
  if (n % 2 != 0) {
    ++kk;
  }
  int pos = NO_POS;
  for (int k = 1; k < kk; ++k) {
    pos = k;
    for (int i = k; i < n; ++i) {
      if (t[i - k] != t[i]) {
        pos = NO_POS;
        break;
      }
    }    
    if (pos != NO_POS) {
      break;
    }
  }
  if (pos == NO_POS) {
    return Res { .yes = false };
  }  
  return Res { 
    .yes = true, 
    .s = t.substr(pos, n - pos) 
  };  
}

int main() {
  string t;
  cin >> t;  
  Res res = solve(t);
  if (res.yes) {
    cout << "YES" << '\n';
    cout << res.s << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}