#include <bits/stdc++.h>

using namespace std;

bool le(double y, double x) {
  return y < x;
}

int solve(double x) {  
  int i = 0;
  double n = 2.0;
  double y = 0.0;
  while (le(y, x)) {
    y += 1.0 / n;
    n += 1.0;
    i += 1;
  }
  return i;
}

int main() {
  double x;
  cin >> x;
  cout << solve(x) << " card(s)" << endl;
  return 0;
}