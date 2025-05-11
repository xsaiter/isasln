#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
  int d = a % 10;
  int ans = 1;
  while(b--) {
    ans *= d;
    ans %= 10;
  }
  return ans;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << solve(a, b) << endl;
  return 0;
}