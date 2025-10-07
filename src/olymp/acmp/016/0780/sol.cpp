#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  int m = 0;
  int i = 0;
  while (1) {
    m = i * (i + 1) / 2;
    if (m == n) {
      break;
    }
    ++i;    
  }
  return i;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}