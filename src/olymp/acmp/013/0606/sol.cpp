#include <bits/stdc++.h>

using namespace std;

bool check(int a, int b, int c) {
  return a < b + c;
}

bool solve(int a, int b, int c) {    
  return check(a, b, c) 
    && check(b, a, c)
    && check(c, a, b);
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (solve(a, b, c) ? "YES" : "NO") << endl;
  return 0;
}