#include <bits/stdc++.h>

using namespace std;

bool solve(int a, int b) {
  if (a == 0 && b == 0)  {
    return true;
  }
  bool p = (a + b) % 3 == 0;
  bool q = false;
  if (a <= b) {
    if (a * 2 >= b) {
      q = true;
    }
  } else {
    if (b * 2 >= a) {
      q = true;
    }
  }
  return p && q;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (solve(a, b) ? "YES" : "NO") << endl;
  }
  return 0;
}