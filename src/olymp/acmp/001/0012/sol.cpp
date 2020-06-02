#include <bits/stdc++.h>

using namespace std;

using ti = long long;

ti cp(ti ax, ti ay, ti bx, ti by, ti cx, ti cy) {
  return (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
}

struct It {
  ti x, y, x1, y1, x2, y2, x3, y3, x4, y4;

  bool inside() const {
    auto r1 = cp(x1, y1, x2, y2, x, y);
    auto r2 = cp(x2, y2, x3, y3, x, y);
    auto r3 = cp(x3, y3, x4, y4, x, y);
    auto r4 = cp(x4, y4, x1, y1, x, y);
    
    return (r1 >= 0 && r2 >= 0 && r3 >= 0 && r4 >= 0) || (r1 <= 0 && r2 <= 0 && r3 <= 0 && r4 <= 0);
  }
};

int main() {
  int n;
  cin >> n;
  vector<It> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].x3 >> a[i].y3 >> a[i].x4 >> a[i].y4;
  }
  int res = 0; 
  for (int i = 0 ; i < n; ++i) {
    if (a[i].inside()) {
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}