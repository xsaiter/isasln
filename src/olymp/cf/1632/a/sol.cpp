#include <bits/stdc++.h>

using namespace std;

bool solve(string &s, int n) { 
  if (n == 1) return true;
  return n == 2 && s[0] != s[1];
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    cout << (solve(s, n) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}