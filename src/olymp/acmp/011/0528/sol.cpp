#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(L n, L k) {  
  L ans = n * k * (k + 1) / 2;
  ans -= 8;
  return ans;
}

int main() {
  L n, k;
  cin >> n >> k;
  cout << solve(n, k) << endl;
  return 0;
}