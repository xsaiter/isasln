#include <bits/stdc++.h>

using namespace std;

bool is_b(int x, int y) {
  if (x % 2 == 1) {
    return y % 2 == 1;
  }
  return y % 2 == 0;
}

bool solve(int x1, int y1, int x2, int y2) {  
  return is_b(x1, y1) == is_b(x2, y2);
}

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << (solve(x1, y1, x2, y2) ? "YES" : "NO") << endl;
  return 0;
}