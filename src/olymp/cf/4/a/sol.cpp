#include <bits/stdc++.h>

using namespace std;

bool solve(int w) {
  if (w < 4) {
    return false;
  }
  if (w % 2 == 0) {
    return true;
  }
  return false;
}

int main() {
  int w;
  cin >> w;
  cout << (solve(w) ? "YES" : "NO") << endl;
  return 0;
}