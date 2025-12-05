#include <bits/stdc++.h>

using namespace std;

auto solve(int a, int b, int c) {
  int x, y;
  x = gcd(a, b); 
  return make_tuple(x, y);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    auto [x, y] = solve(a, b, c);
    cout << x << " " << y << "\n";
  }
  cout << endl;
  return 0;
}