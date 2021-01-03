#include <bits/stdc++.h>

using namespace std;

int solve(const string &s) {  
  int n = (int)s.size();
  int k0 = 0, k1 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') ++k0; else ++k1;
  }
  int res = min(k0, k1);
  int p0 = 0, p1 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') { 
      ++p0;
      --k0;
    } else {
      ++p1;
      --k1;
    }
    res = min(res, p0 + k1);
    res = min(res, p1 + k0);
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << "\n";
  }
  cout << endl;
  return 0;
}