#include <bits/stdc++.h>

using namespace std;

int solve(int k) {  
  double x = (-1.0 + sqrt(1 + 8 * k)) / 2.0;
  return (int)floor(x);  
}

int main() {
  int k;
  cin >> k;
  cout << solve(k) << endl;
  return 0;
}