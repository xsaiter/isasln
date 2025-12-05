#include <bits/stdc++.h>

using namespace std;

struct P {
  double x, y;
};

int main() {
  int n = 3;
  vector<P> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  return 0;
}