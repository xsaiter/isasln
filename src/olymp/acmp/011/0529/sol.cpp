#include<bits/stdc++.h>

using namespace std;

double solve(int x, int y, int x2, int y2) {
  double ans = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
  return ans;
}

int main() {
  int x, y;
  cin >> x >> y;
  int x2, y2;
  cin >> x2 >> y2;
  double ans = solve(x, y, x2, y2);
  printf("%.5f", ans);
  return 0;
}