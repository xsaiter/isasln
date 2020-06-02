#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;

int main() {
  int x1, y1, r1;
  int x2, y2, r2;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;

  double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

  auto c1 = isgreaterequal(r1 + r2, d);
  auto c2 = isgreaterequal(r1 + d, r2);
  auto c3 = isgreaterequal(r2 + d, r1);

  if (c1 && c2 && c3) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}