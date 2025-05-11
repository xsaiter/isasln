#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

int main() {
  vector<P> a(3);
  cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y;
  sort(a.begin(), a.end(), 
    [](const P &l, const P &r) {
      if (l.y == r.y) {
        return l.x < r.x;
      }
      return l.y < r.y;
  });
  P b;
  return 0;
}