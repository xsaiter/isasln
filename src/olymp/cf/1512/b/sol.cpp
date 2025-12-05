#include <bits/stdc++.h>

using namespace std;

struct R {
  int x = 0, y = 0;
};

void solve(vector<string> &a, int n) {
  vector<R> r(4);
  int k = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == '*') {
        r[k].y = i; r[k].x = j; ++k;
      }
    }
  }
  if (r[0].y < r[1].y) {
    if (r[0].x < r[1].x) {
      r[2].y = r[1].y; r[2].x = r[0].x;
      r[3].y = r[0].y; r[3].x = r[1].x;
    } else if (r[0].x > r[1].x) {
      r[2].y = r[0].y; r[2].x = r[1].x;
      r[3].y = r[1].y; r[3].x = r[0].x;
    } else {
      int nx = r[0].x + 1; if (nx == n) nx = r[0].x - 1;
      r[2].y = r[0].y; r[2].x = nx;
      r[3].y = r[1].y; r[3].x = nx;      
    }
  } else if (r[0].y > r[1].y) {
    if (r[0].x < r[1].x) {
      r[2].y = r[0].y; r[2].x = r[1].x;
      r[3].y = r[1].y; r[3].x = r[0].x;
    } else if (r[0].x > r[1].x) {
      r[2].y = r[1].y; r[2].x = r[0].x;
      r[3].y = r[0].y; r[3].x = r[1].x;
    } else {
      int nx = r[0].x + 1; if (nx == n) nx = r[0].x - 1;
      r[2].y = r[1].y; r[2].x = nx;
      r[3].y = r[0].y; r[3].x = nx;      
    }
  } else {
    if (r[0].x < r[1].x) {
      int ny = r[0].y + 1; if (ny == n) ny = r[0].y - 1;
      r[2].y = ny; r[2].x = r[0].x;
      r[3].y = ny; r[3].x = r[1].x;
    } else {
      int ny = r[0].y + 1; if (ny == n) ny = r[0].y - 1;
      r[2].y = ny; r[2].x = r[1].x;
      r[3].y = ny; r[3].x = r[0].x;
    }
  }
  a[r[2].y][r[2].x] = '*';
  a[r[3].y][r[3].x] = '*';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    solve(a, n);
    for (int i = 0; i < n; ++i) {
      cout << a[i] << '\n';
    }    
  }
  cout << endl;
  return 0;
}