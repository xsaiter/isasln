#include <bits/stdc++.h>

using namespace std;

bool solve(int n) {
  if (n == 0) {
    return false;
  }
  if (n == 1) {
    return true;
  }
  if (n == 2) {
    return true;
  }
  while (n != 1) {
    if (n % 2 != 0) {
      return false;
    }
    n /= 2;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  cout << (solve(n) ? "YES" : "NO") << endl;
  return 0;
}