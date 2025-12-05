#include <bits/stdc++.h>

using namespace std;

bool solve(int a, int b) {
  if (a == 0 && b == 0) {
    return true;
  }
  if (a == 0) {
    return b % 2 == 0;
  }
  if (b == 0) {
    return a % 2 == 0;
  }
  if (a % 2 == 0 && b % 2 == 0) {
    return true;
  }
  if (a % 2 == 0) {    
    return a >= 2;    
  }  
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (solve(a, b) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}