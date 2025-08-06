#include <bits/stdc++.h>

using namespace std;

const int M = 10;

int ci(char c) {
  return (int)c - (int)'0';
}

int len(const string &s) {
  return (int)s.size();
}

int pos(const string &s) {  
  const int n = len(s);
  for (int i = 0; i < n - 1; ++i) {
    int d = ci(s[i + 1]) - ci(s[i]);
    if (d > 0) {
      return i;
    } 
  }  
  int ans = -1;
  int m = M;
  for (int i = 0; i < n; ++i) {
    int d = ci(s[i]);
    if (d < m) {
      m = d;
      ans = i;
    }
  }
  return ans;
}

string rm(const string &s, int k) {
  const int n = len(s);
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    if (i != k) {
      oss << s[i];
    }    
  }
  return oss.str();
}

int main() {
  string s;
  cin >> s;    
  string t = rm(s, pos(s));  
  cout << rm(t, pos(t)) << endl;
  return 0;
}