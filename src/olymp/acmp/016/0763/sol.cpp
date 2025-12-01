#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y) {
  if (x == 1 && y == 1) {
    return 0;
  }
  if (x == y) {
    return 2;
  }  
  return 1;
}

int main() {
  int x, y;
  cin >> x >> y;
  cout << solve(x, y) << endl;
  return 0;
}