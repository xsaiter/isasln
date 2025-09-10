#include <bits/stdc++.h>

using namespace std;

bool is_poly(const string &s, int p, int q) {    
  while (p < q) {
    if (s[p] != s[q]) {
      return false;
    }
    ++p; --q;
  }
  return true;
}

int all_same(const string &s, int n) {
  char c = s[0];
  for (int i = 1; i < n; ++i) {
    if (c != s[i]) {
      return false;
    }
  }
  return true;
}

string solve(const string &s) {
  const string NO = "NO SOLUTION";
  int n = (int)s.size();  
  if (all_same(s, n)) {
    return NO;
  }
  if (is_poly(s, 0, n - 1)) {
    return s.substr(0, n - 1);
  }
  return s;
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}