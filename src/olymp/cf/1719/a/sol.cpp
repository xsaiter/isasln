#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m) {
  if (n == 1 && m == 1) {
    return 2;
  }
  if (n == 1) {
    if (m % 2 == 0) {
      return 1;
    } else {
      return 2;
    }
  }
  if (m == 1) {
    if (n % 2 == 0) {
      return 1;
    } else {
      return 2;
    }
  }
  if (n % 2 == 0) {
    if (m % 2 == 0) {
      return 2;
    } else {
      return 1;
    } 
  } else {
    if (m % 2 == 0) {
      return 1;
    } else {
      return 2;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << (solve(n, m) == 1 ? "Burenka" : "Tonya") << '\n';
  }
  cout << endl;
  return 0;
}