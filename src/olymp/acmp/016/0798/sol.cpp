#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, n, i, j, c;
  cin >> m >> n >> i >> j >> c;
  int r = 0;
  if (n != m) {
    if (m % 2 == 0) {
    } else {
      if (i % 2 == 0) {
        if (c == 0) {
          r = 1;
        }    
      }
    }    
  }
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