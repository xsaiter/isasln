#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  if (n == 1) {
    return 0;
  }  
  if (n % 2 == 0) {
    return n / 2;
  }
  return n;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}