#include <bits/stdc++.h>

using namespace std;

int dig(char c) {
  return (int)c - (int)'0';
}

int sq(int x) {
  if (x < 10) {
    return x;
  }  
  int res = 0;  
  while (true) {
    int rem = x % 10;
    res += rem;
    x = (x - rem) / 10;
    if (x < 10) {
      res += x;
      break;
    }
  }
  return sq(res);
}

int sq(const string &s) {
  int k = 0;
  int n = (int)s.size();
  for (int i = 0; i < n; ++i) {
    k += dig(s[i]);
  }
  return sq(k);
}

bool solve(string &s) {
  int n = (int)s.size();
  if (n == 1) {
    return false;
  }
  if (n == 2) {
    return s[0] == s[1];
  }
  for (int i = 1; i <= n - 1; ++i) {
    string a = s.substr(0, i);
    string b = s.substr(i, n - i);
    if (sq(a) == sq(b)) {            
      return true;
    }
  }
  return false;
}

int main() {
  string s;
  cin >> s;  
  cout << (solve(s) ? "YES " : "NO") << endl;      
  return 0;
}