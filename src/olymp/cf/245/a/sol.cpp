#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ax = 0, ay = 0, bx = 0, by = 0;
  while (n--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      ax += x; ay += y;
    } else {
      bx += x; by += y;
    }
  }
  cout << (((ax + ay) <= 2 * ax) ? "LIVE" : "DEAD") << "\n";
  cout << (((bx + by) <= 2 * bx) ? "LIVE" : "DEAD") << endl;
  return 0;
}