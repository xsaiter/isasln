#include <bits/stdc++.h>

using namespace std;
using S = string;

int len(const S &s) {
  return (int)s.size();
}

int f(char c) {
  return (int)c - (int)'0';
}

string solve(const S &a, const S &b) {
  ostringstream oss;
  int n = len(a), m = len(b);
  int i = 0, j = 0;
  while (i < n || j < m) {
    if (i < n) {
      if (j < m) {
        if (f(a[i]) < f(b[j])) {
          oss << a[i]; ++i;
        } else if (f(a[i]) > f(b[j])) {
          oss << b[j]; ++j;
        } else {
          int r = 0;
          int ii = i, jj = j;
          while (ii < n || jj < m) {
            if (ii < n) {
              if (jj < m) {
                if (f(a[ii]) < f(b[jj])) {
                  r = -1; 
                  break;
                } else if (f(a[ii]) > f(b[jj])) {
                  r = 1;
                  break;
                }
              } else {
                r = -1;
                break;
              }
            } else {
              r = 1;
              break;
            }
            ++ii; ++jj;
          }          
          if (r == -1) {
            oss << a[i]; ++i;
          } else if (r == 1) {
            oss << b[j]; ++j;
          } else {
            oss << a[i]; ++i;
          }
        }
      } else {
        oss << a[i]; ++i;
      }
    } else {
      oss << b[j]; ++j;
    }
  }
  return oss.str();
}

int main() {
  S a, b;
  cin >> a >> b;
  cout << solve(a, b) << endl;
  return 0;
}