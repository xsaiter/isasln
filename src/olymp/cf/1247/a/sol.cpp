#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int da, db;
  cin >> da >> db;
  int a = -1, b = -1;
  if (da == db) {
    b = 10 * db + 9; a = b - 1;
  } else if (db - da == 1) {
    if (db == 1 && da == 0) {
      b = 1; a = 0;
    } else {
      b = 10 * db; a = b - 1;     
    }
  } else if (da - db == 1) {
    if (da == 9 && db == 0) {
      a = da; b = db;
    }    
  } else if (da == 9 && db == 1) {
    a = 9; b = 10;
  }
  if (a == -1) {
    cout << -1;
  } else {
    cout << a << " " << b;
  }
  cout << endl;
  return 0;
}