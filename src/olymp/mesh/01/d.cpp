#include <bits/stdc++.h>

using namespace std;

struct Pt {
  int x, y;
};

int cr(const Pt &a, const Pt &b, const Pt &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Pt a, b, c, d;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cin >> c.x >> c.y;
  cin >> d.x >> d.y;
  int t1 = cr(a, b, d);
  int t2 = cr(b, c, d);
  int t3 = cr(c, a, d);
  bool pre1 = t1 >= 0 && t2 >= 0 && t3 >= 0;
  bool pre2 = t1 <= 0 && t2 <= 0 && t3 <= 0;
  if (pre1 || pre2) {
    cout << "In";
  } else {
    cout << "Out";
  }
  cout << endl;
  return 0;
}