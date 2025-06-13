#include <bits/stdc++.h>

using namespace std;

bool solve(const string &s) {
  int m = (int)s.size();  
  if (m % 3 != 0) {
    return false;
  }
  int len = m / 3;
  for (int i = 0; i < len; ++i) {
    if (s[i] != '0' || s[i + len] != '1' || s[i + 2 * len] != '2') {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cout << (solve(s) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}
