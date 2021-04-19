#include <bits/stdc++.h>

using namespace std;

bool is_balanced(const string &s, int from, int to) {
  int k = 0;
  for (int i = from; i < to; ++i) {
    if (s[i] == '(') ++k; else --k;
  }
  return (k == 0);
}

int solve(const string &s, int n) {
  if (!is_balanced(s, 0, n)) return -1;
  int res = 0;
  int k = 0;
  bool is_unbalanced = false;
  int unbalanced_len = 0;
  for (int i = 0; i < n; ++i) {
    if (is_unbalanced) {
      if (s[i] == ')') ++k; else --k;
      ++unbalanced_len;
      if (k == 0) {
        res += unbalanced_len;
        is_unbalanced = false;
      }
    } else {
      if (s[i] == '(') ++k; else --k;
      if (k < 0) {
        is_unbalanced = true;        
        unbalanced_len = 1;
        k = 1;
      }
    }    
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << solve(s, n) << endl;
  return 0;
}