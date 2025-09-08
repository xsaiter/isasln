#include <bits/stdc++.h>

using namespace std;

using L = long long;

L f(L n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n % 2 == 0) {
    return f(n / 2);
  }
  L k = (n - 1) / 2;
  return f(k) + f(k + 1);  
}

L solve(L n) {
  return f(n);
}

int main() {
  L n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}


