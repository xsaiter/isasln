#include <bits/stdc++.h>

using namespace std;

string solve(string &s, int n) {
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      oss << 'L';
    } else if (s[i] == 'R') {
      oss << 'R';
    } else if (s[i] == 'U') {
      oss << 'D';
    } else if (s[i] == 'D') {
      oss << 'U';
    }
  }
  return oss.str();
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s, n) << '\n';
  }
  cout << endl;
  return 0;
}