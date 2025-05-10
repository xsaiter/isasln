#include <bits/stdc++.h>

using namespace std;
using L = long long;

L solve(L n) {  
  if (n < 4) {
   return n;
  }  
  L ans = 1;
  L rem = n % 3;  
  if (rem == 0) {        
    ans = pow(3, n / 3);    
  } else {        
    ans = pow(3, (n - rem) / 3); 
    if (rem == 1) {
      ans /= 3;
      ans *= 4;
    } else if (rem == 2) {
      ans *= 2;
    }
  }
  return ans;
}

int main() {
  L n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}