#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x = min(min(a, b), c);
  int y = max(max(a, b), c);
  cout << y - x << endl;
  return 0;
}