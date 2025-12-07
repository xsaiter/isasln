#include <bits/stdc++.h>

using namespace std;

bool ok(const string &s, int p, int q) {
  int cnt = 0;
  for (int i = p; i <= q; ++i) {
    if (s[i] == '(') {
      ++cnt;
    } else {
      --cnt;
    }
    if (cnt < 0) {
      return false;
    }
  }
  return cnt == 0;
}

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();  
  vector<int> dp(n + 1);
  for (int i = 0; i < n; ++i) {
    
  }
  return 0;
}