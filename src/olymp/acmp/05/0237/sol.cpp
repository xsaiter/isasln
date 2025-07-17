#include <bits/stdc++.h>

using namespace std;

using S = vector<string>;
using B = vector<bool>;

bool check(int n, const S &a, int i, int j, char c, vector<B> &rr, int dir) {
  int ii = i, jj = j;
  if (dir == 1) {    
    ii += 1;
  } else if (dir == 2) {
    ii -= 1;
  } else if (dir == 3) {
    jj += 1;
  } else if (dir == 4) {
    jj -= 1;
  }
  if (ii == n || ii == -1 || jj == n || jj == -1) {
    return false;
  }
  return !rr[ii][jj] && a[ii][jj] == c;
}

bool proc(int n, const S &a, int ii, int jj, int pos, const string &s, vector<B> &rr, vector<B> &r) {
  int len = (int)s.size();
  for (int i = 0; i < len; ++i) {
    bool c1 = check(n, a, ii, jj, s[i], rr, 1);
    if (c1) {
     
    }
  }
  return true;
}

string solve(int n, int m, const S &a, const S &b) {  
  vector<B> rr(n, B(n));
  for (int k = 0; k < m; ++k) {    
    char ch = b[k][0];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == ch && !rr[i][j]) {
          int len = (int)b[k].size();
          vector<B> r(n, B(n));
          if (proc(n, a, i, j, 0, b[k], rr, r)) {
            for (int ii = 0; ii < n; ++ii) {
              for (int jj = 0; jj < n; ++jj) {
                if (r[ii][jj]) {
                  rr[ii][jj] = true;
                }
              }
            }
          }
        }
      }
    }
  }
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!rr[i][j]) {
        oss << a[i][j];
      }
    }
  }
  return oss.str();
}

int main() {
  int n, m;
  cin >> n >> m;
  S a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  S b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  cout << solve(n, m, a, b) << endl;
  return 0;
}