#include <bits/stdc++.h>

using namespace std;

bool solve(int n) {
  string s = to_string(n);
  return s[0] == s[3] && s[1] == s[2];  
}

int main() {
  int n;
  cin >> n;
  cout << (solve(n) ? "YES" : "NO") << endl;
  return 0;
}