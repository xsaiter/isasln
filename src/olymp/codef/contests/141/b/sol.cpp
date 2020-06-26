#include <bits/stdc++.h>

using namespace std;

bool inside(int a, int x) {
  return (-a < x && x < a);
}

bool inside2(int a, int x) {
  return (((double)-a / 2) < x && x < ((double)a / 2));
}

int solve(int a, int x, int y) {
  int t = y % a;
  if (t == 0) return -1;
  int h = (y - t) / a + 1;
  if (h < 3) {    
    if (inside2(a, x)) return h;
  } else {
    bool ins = (h % 2 == 0) ? inside2(a, x) : inside(a, x);    
    if (ins) {
      int p = h - 2;
      int r;
      if (p == 1) {
        if (x == 0) return -1;
        if (x < 0) r = 1; else r = 2;
      } else if (p % 2 == 0) {
        r = (p / 2) * 2 + (p / 2);
      } else {
        int q = (p - 1) / 2;        
        r = q + (p - q) * 2;
        if (x == 0) return -1;
        if (x < 0) --r;
      }
      return 2 + r;
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, x, y;
  cin >> a >> x >> y;
  cout << solve(a, x, y) << endl;
  return 0;
}