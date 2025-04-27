#include <bits/stdc++.h>

using namespace std;

int to_digit(char c) {
  return (int)c - (int)'0';
}

int solve(string &s) {  
  int a, b;
  bool is_plus = (s[1] == '+');
  if (s[4] == 'x') {
    a = to_digit(s[0]);
    b = to_digit(s[2]);
    if (is_plus) {
      return a + b;
    }
    return a - b;
  }
  int c = to_digit(s[4]); 
  if (s[0] == 'x') {
    a = to_digit(s[2]);
    if (is_plus) {
      return c - a;
    }
    return c + a;
  } 
  b = to_digit(s[0]);
  if (is_plus) {
    return c - b;
  }
  return b - c;
    
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}