#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y, int z) {
  return x + y - z;
}

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int res = solve(x, y, z);
  if (res < 0) {
    cout << "Impossible" << endl;
  } else {
    cout << res << endl;
  }
  return 0;
}