#include <bits/stdc++.h>

using namespace std;

int nod(int n, int m) {  
  if (n == m)  return n;
  int d = n - m;
  int res;
  if (d < 0) {
    d = -d;  
    res = nod(n, d);
  } else {
    res = nod(m, d); 
  }    
  return res;
}

int nok(int n, int m) {
  return n * m / nod(n, m);
}

int period(string &s, int n) {
  int res = 1;
  for (int i = 0; i < n; ++i) {
    
  }
  return res;
}

string solve(string &s, string &t) {  
  string no = "-1";
  int n = (int)s.size();
  int m = (int)t.size();
  bool ok = true;
  char c = s[0];
  for (int i = 0; i < n; ++i) {
    if (s[i] != c) {
      ok = false;
      break;
    }
  }
  if (all) {
    for (int i = 0; i < m; ++i) {
      if (t[i] != c) {
        ok = false;
      }
    }
    if (ok) {
      return string(nok(n, m), c);
    }
  }
  ok = true;
  if (n == m) {
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      return s;
    }
    return no;
  }  

  ok = true;
  for (int i = 0; i < n; ++i) {}

  return no;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << '\n';
  }
  cout << endl;
  return 0;
}