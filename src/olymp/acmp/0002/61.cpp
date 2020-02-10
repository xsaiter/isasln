#include <bits/stdc++.h>

using namespace std;

int main() {
  constexpr int n = 8;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      x += a[i];
    } else {
      y += a[i];
    }
  }
  if (x > y) {
    cout << "1";
  } else if (x < y) {
    cout << "2";
  } else {
    cout << "DRAW";
  }
  cout << endl;
  return 0;
}