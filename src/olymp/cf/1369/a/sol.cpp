#include <bits/stdc++.h>

using namespace std;

bool solve(int n) {
  if (n == 3) {
    return false;
  }
  if (n == 4) {
    return true;
  }
  return n % 4 == 0;
}

int main() {
  int t;
  cin >> t;  
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    cout << (solve(n) == true ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}