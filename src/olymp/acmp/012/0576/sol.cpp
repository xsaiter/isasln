#include <bits/stdc++.h>

using namespace std;

int solve(int n) {  
  int ans = 0;
  for (int x = 1; x < n; ++x) {
    if (gcd(x, n) == 1) {
      ++ans;
    }
  }       
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
