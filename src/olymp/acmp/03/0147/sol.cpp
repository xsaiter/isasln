#include <bits/stdc++.h>

using namespace std;

int solve(int n) {  
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 1;
  }
  int x = 1, y = 1;
  for (int i = 2; i < n; ++i) {
    int tmp = y;
    y = x + y;
    x = tmp;
  }
  return y;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}