#include <bits/stdc++.h>

using namespace std;

string solve(string &s) {
  int n = (int)s.size();
  ostringstream oss;  
  int a = 1, b = 1;
  oss << s[b - 1];
  while (true) {
    int t = b;
    b = a + b;
    a = t;
    if (b - 1 < n) {
      oss << s[b - 1];
    } else {
      break;
    }
  }  
  return oss.str();
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}