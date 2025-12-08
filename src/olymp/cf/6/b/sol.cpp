#include <bits/stdc++.h>

using namespace std;

struct C {
  int i, j;
};

C cl(int n, int m, char c, const vector<string> &a) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == c) {
        return C {.i = i, .j = j};
      }      
    }
  }
  throw "no cl";
}

C cr(int n, int m, char c, const vector<string> &a) {
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (a[i][j] == c) {
        return C {.i = i, .j = j};
      }      
    }
  }
  throw "no cr";
}

int solve(int n, int m, char c, const vector<string> &a) {  
  C l = cl(n, m, c, a); 
  C r = cr(n, m, c, a); 
  int ans = 0;
  set<char> cc;
  if (l.i - 1 >= 0) {
    for (int j = l.j; j <= r.j; ++j) {
      char x = a[l.i - 1][j];
      if (x != '.' && !cc.contains(x)) {
        cc.insert(x);
        ans += 1;      
      }
    }
  }
  cc.clear();
  if (r.i + 1 < n) {
    for (int j = l.j; j <= r.j; ++j) {
      char x = a[r.i + 1][j];
      if (x != '.' && !cc.contains(x)) {
        cc.insert(x);
        ans += 1;      
      }
    }
  }
  cc.clear();
  if (l.j - 1 >= 0) {
    for (int i = l.i; i <= r.i; ++i) {
      char x = a[i][l.j - 1];
      if (x != '.' && !cc.contains(x)) {
        cc.insert(x);
        ans += 1;      
      }
    }
  }
  cc.clear();
  if (r.j + 1 < m) {
    for (int i = l.i; i <= r.i; ++i) {
      char x = a[i][r.j + 1];
      if (x != '.' && !cc.contains(x)) {
        cc.insert(x);
        ans += 1;      
      }
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  char c;
  cin >> c;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, m, c, a) << endl;
  return 0;
}