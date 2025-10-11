#include <bits/stdc++.h>

using namespace std;

int solve(int m, int n, int i, int j, int c) {
  if (m % 2 == 0 || n % 2 == 0) {
    return 0;
  }  
  if (i > 1 && i % 2 == 0) {
    if (c == 0) {
      c = 1;
    } else {
      c = 0;
    }
  }
  if (j > 1 && j % 2 == 0) {
    if (c == 0) {
      c = 1;
    } else {
      c = 0;
    }
  }
  if (c == 0) {
    return -1;
  }
  return 1;
}

int main() {
  int m, n, i, j, c;
  cin >> m >> n >> i >> j >> c;
  int r = solve(m, n, i, j, c);  
  if (r == 0) {
    cout << "equal";
  } else if (r == 1) {
    cout << "white";
  } else {
    cout << "black";
  }
  cout << endl;
  return 0;
}