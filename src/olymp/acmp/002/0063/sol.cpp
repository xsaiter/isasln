#include <bits/stdc++.h>

using namespace std;

int main() {
  int s, p;
  cin >> s >> p;
  int x = (s + sqrt(s * s - 4 * p)) / 2;
  int y = p / x;
  if (x > y) {
    swap(x, y);
  }
  cout << x << " " << y << endl;
  return 0;
}