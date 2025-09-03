#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, const string &s) {
  if (s == "freeze") {
    if (a < b) {
      return a;
    } else if (a > b) {
      return b;
    } 
    return a;
  } else if (s == "heat") {
    if (a < b) {
      return b;
    } else if (a > b) {
      return a;
    }
    return a;
  } else if (s == "auto") {
    return b;
  } else if (s == "fan") {
    return a;
  }
  throw "Unexpected mode";
}

int main() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  cout << solve(a, b, s) << endl;
  return 0;
}