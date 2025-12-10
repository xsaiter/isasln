#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.0001;

struct E {
  char c;
  int v;
  int x;
  int rnd;

  void fill(int s) {
    double a = pct(s);
    int ca = (int)a;
    if (abs(a - (double)ca) < EPS) {      
      rnd = false;
    } else {
      rnd = true;
    }
    x = ca;
  }

  double pct(int s) const {
    return (double)v * 100.0 / (double)s;
  }
};

int main() {
  int n;
  cin >> n;
  vector<E> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].c >> a[i].v;
  }  
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s += a[i].v;
  }
  for (int i = 0; i < n; ++i) {
    a[i].fill(s);
  }  
  int sx = 0;
  for (int i = 0; i < n; ++i) {
    sx += a[i].x;
  }
  vector<int> b(n);
  int dx = 100 - sx;    
  if (dx > 0) {    
    for (int i = 0; i < n; ++i) {
      if (!a[i].rnd) {
        continue;
      }
      if (a[i].c == '+') {
        a[i].x += 1;
        dx -= 1;
        if (dx == 0) {
          break;
        }
      }
    }
    if (dx > 0) {
      for (int i = 0; i < n; ++i) {
        if (!a[i].rnd) {
          continue;
        }
        if (a[i].c == '-') {
          a[i].x += 1;
          dx -= 1;
          if (dx == 0) {
            break;
          }
        }
      }
    }
  }  
  for (int i = 0; i < n; ++i) {
    cout << a[i].x << '\n';
  }
  cout << endl;
  return 0;
}