#include <bits/stdc++.h>

using namespace std;
using L = long long;

L solve(const string& s) {
  int n = (int)s.size();
  L dp_a = 0, dp_b = 0, dp_c = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      dp_a += 1;
    } else if (s[i] == 'b') {
      dp_b += dp_a;
    } else if (s[i] == 'c') {
      dp_c += dp_b;
    }
  }
  return dp_c;
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}