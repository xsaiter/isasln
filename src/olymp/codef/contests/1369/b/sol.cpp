#include <bits/stdc++.h>

using namespace std;

string solve(int n, string &s) {
  ostringstream res;
  int pos = -1;
  vector<int> a(n);
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == '1') {
      if (s[i + 1] == '0') {
        if (s[i + 2] == '1') {
          res << s[i + 1];
        } else {
          res <<
        }
      } else {
        res << s[i];
      }
    }
  }
  return res.str();
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(n, s) << '\n';
  }
  cout << endl;
  return 0;
}