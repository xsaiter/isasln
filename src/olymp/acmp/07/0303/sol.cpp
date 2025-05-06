#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dig(char c) {
  return (int)(c - '0');
}

int solve(const string &s, int n) {
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = dig(s[i]);
  }
  int ans = -INF;
  for (int i = 0; i < n; ++i) {
    int res = 0;
    int p = 1;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        res += a[j] * p;
        if (p == 1) {
          p = -1;
        } else {
          p = 1;
        }
      }      
    }
    ans = max(ans, res);
  }
  return ans;
}

int main() {
  string s;  
  cin >> s;
  int n = (int)s.size();
  cout << solve(s, n) << endl;
  return 0;
}