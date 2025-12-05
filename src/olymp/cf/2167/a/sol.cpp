#include <bits/stdc++.h>

using namespace std;

bool solve(int a, int b, int c, int d) {
  return a == b && a == c && a == d;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (solve(a, b, c, d) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}