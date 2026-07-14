#include <bits/stdc++.h>

using namespace std;

bool f(vector<int> &a) {
  for (int i = 0; i < 4; ++i) {    
    int x = 0;
    for (int j = 0; j < 4; ++j) {
      if (i != j) {
        x += a[j];
      }
    }
    if (a[i] == x) {
      return true;
    }
  }
  return false;
}

bool f2(vector<int> &a) {
  for (int i = 0; i < 4; ++i) {
    for (int ii = 0; ii < 4; ++ii) {
      if (i != ii) {
        int x = a[i] + a[ii];
        int y = 0;
        for (int j = 0; j < 4; ++j) {
          if (j != i && j != ii) {
            y += a[j];
          }
        }
        if (x == y) {
          return true;
        }
      }
    }
  }
  return false;
}

bool solve(vector<int> &a) {
  return f(a) || f2(a);
}

int main() {
  vector<int> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  cout << (solve(a) ? "YES" : "NO") << endl;
  return 0;
}