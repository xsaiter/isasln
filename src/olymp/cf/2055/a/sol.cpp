#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int a, int b) {  
  int d = abs(a - b) - 1;  
  if (d == 0) {
    return false;
  }
  return (d % 2 == 1);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    cout << (solve(n, a, b) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}