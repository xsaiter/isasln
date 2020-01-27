#include <bits/stdc++.h>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int xa, ya;
  cin >> xa >> ya;
  int xb, yb;
  if (x1 == x2) {
    yb = ya;
    if (x1 == xa) {
      xb = xa;
    } else if (x1 < xa) {
      xb = x1 - (xa - x1);
    } else {
      xb = x1 + (x1 - xa);
    }
  } else if (y1 == y2) {
    xb = xa;
    if (y1 == ya) {
      yb = ya;
    } else if (y1 < ya) {
      yb = y1 - (ya - y1);
    } else {
      yb = y1 + (y1 - ya);
    }
  }
  cout << xb << " " << yb << endl;
  return 0;
}