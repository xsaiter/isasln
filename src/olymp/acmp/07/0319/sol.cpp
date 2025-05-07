#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

int solve(const P &a, const P &b) {
  int res = 0;
  int min_x = min(a.x, b.x);
  int max_x = max(a.x, b.x);
  int min_y = min(a.y, b.y);
  int max_y = max(a.y, b.y);

  return res;
}

int main() {
  P a, b;
  cin >> a.x >> a.y; 
  cin >> b.x >> b.y;
  cout << solve(a, b) << endl;
  return 0;
}