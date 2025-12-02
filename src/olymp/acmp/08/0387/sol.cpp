#include <bits/stdc++.h>

using namespace std;

bool has_left_rec(const string &s) {
  int n = (int)s.size();
  auto k = s.find("->");
  string a = s.substr(0, k);
  string b = s.substr(k + 2, n - k - 2);  
  int na = (int)a.size();
  int nb = (int)b.size();
  if (na > nb) {
    return false;
  }
  for (int i = 0; i < na; ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (has_left_rec(s)) {
      ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
}