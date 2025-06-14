#include <bits/stdc++.h>

using namespace std;

struct C {
  string s;
  int x, y, r;
  int m;
  bool is_active;
};

struct R {
  string s;
  int m;
};

bool is_inside(const C &c, int x, int y) {
  return (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y) <= c.r * c.r;
}

vector<R> solve(int n, vector<C> &a, int x, int y) {  
  for (int i = 0; i < n; ++i) {
    if (is_inside(a[i], x, y)) {      
      a[i].m += 1;
    }
  }  
  for (int i = 0; i < n; ++i) {
    if (!a[i].is_active) {
      continue;
    }
    for (int j = i + 1; j < n; ++j) {      
      if (a[i].s == a[j].s) {
        if (a[j].is_active) {          
          a[j].is_active = false;
          a[i].m += a[j].m;
        }
      }
    }
  }
  vector<R> b;
  for (int i = 0; i < n; ++i) {
    if (a[i].is_active) {
      b.push_back({ .s = a[i].s, .m = a[i].m });
    }
  }
  return b;
}

int main() {
  int n;
  cin >> n;
  vector<C> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].s;
    cin >> a[i].x >> a[i].y >> a[i].r;
    a[i].m = 0;
    a[i].is_active = true;
  }
  int x, y;
  cin >> x >> y;
  vector<R> b = solve(n, a, x, y);
  int nb = (int)b.size();
  cout << nb << '\n';
  for (int i = 0; i < nb; ++i) {
    cout << b[i].s << ' ' << b[i].m << '\n';
  }
  cout << endl;
  return 0;
}