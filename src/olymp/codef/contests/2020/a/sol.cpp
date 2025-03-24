#include <bits/stdc++.h>

using namespace std;
using L = long long;

// (n - k^x) -> 0, where x is non-negative number 

int solve(int n, int k) {  
  int res = 0;
  if (k == 1) {
    return n;
  }  
  while (n != 0) {
    int rem = n % k;
    res += rem;
    n = (n - rem) / k;    
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << '\n';
  }
  cout << endl;
  return 0;
}