#include <bits/stdc++.h>

using namespace std;

bool solve(int w, int h, int r) {
  int d = 2 * r;
  return w >= d && h >= d;
}

int main() {
  int w, h, r;
  cin >> w >> h >> r;
  cout << (solve(w, h, r) ? "YES" : "NO") << endl;
  return 0;
}