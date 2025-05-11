#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  if (n < 3) {
    return 0;
  }
  if (n == 3) {
    return 2;
  }
  return (n - 1) * (n - 1) - (n - 1);  
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}