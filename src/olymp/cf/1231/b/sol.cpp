#include <bits/stdc++.h>

using namespace std;

string solve(int n, int k, string &s) {
  if (k == 0) {
    return s;
  }
  if (n == 1) {    
    return "0";
  }
  ostringstream oss;
  if (s[0] != '1') {
    --k;
    oss << '1';
  } else {
    oss << s[0];
  }
  for (int i = 1; i < n; ++i) {    
    if (k == 0) {
      for (int j = i; j < n; ++j) {
        oss << s[j];
      }
      break;
    }
    if (s[i] != '0') {      
      oss << '0';
      --k;
    } else {
      oss << s[i];
    }
  }
  return oss.str();
}

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  cout << solve(n, k, s) << endl;
  return 0;
}