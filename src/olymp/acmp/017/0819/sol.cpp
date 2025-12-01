#include <bits/stdc++.h>

using namespace std;

using L = long long;

int main() {
  L a, b, c;
  cin >> a >> b >> c;
  cout << 2 * a * b + 2 * a * c + 2 * b * c << ' ';
  cout << a * b * c << endl;
  return 0;
}