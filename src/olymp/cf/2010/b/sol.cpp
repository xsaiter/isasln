#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {  
  if (a == 1) {
    if (b == 2) {
      return 3;
    } else {
      return 2;
    }
  } else if (a == 2) {
    if (b == 1) {
      return 3;
    } else {
      return 1;
    }
  }
  if (b == 1) {
    return 2;
  }
  return 1;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << solve(a, b) << endl;
  return 0;
}
