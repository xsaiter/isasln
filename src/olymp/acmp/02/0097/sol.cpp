#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

struct V {
  P a, b;
  int r;
};

int solve(int n, vector<V> &v) {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<V> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].a.x >> v[i].a.y;
    cin >> v[i].b.x >> v[i].b.y;
    cin >> v[i].r;
  }
  return 0;
}