#include <bits/stdc++.h>

using namespace std;

bool solve(string &s, int x) {
  if (s == "School" && x % 2 == 0) {
    return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;  
  int x;
  cin >> x;
  cout << (solve(s, x) ? "Yes" : "No") << endl;
  return 0;
}