#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long a, b; // a - b = n  
  if (n == 1) {
    a = 9;
    b = 8;
  } else if (n == 2) {
    a = 10;
    b = 8;
  } else {
    a = n * 3;
    b = n * 2;
  }  
  cout << a << " " << b << endl;
  return 0;
}