#include <bits/stdc++.h>

using namespace std;

int dig(char c) {
  return (int)c - (int)'0';
}

string build(int n) {
}

int solve(int n) {  
  string s = build(n);
  return dig(s[n - 1])
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}