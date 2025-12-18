#include <bits/stdc++.h>

using namespace std;

int ord(char c) {
  return (int)c - (int)'0';
}

string solve(string &s) {
  int n = (int)s.size();
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = ord(s[i]);
  }
  int j = 1;
  while (j < n) {
    int k = j;
    while (k > 0 && a[k - 1] < a[k] - 1) {      
      int tmp = a[k] - 1;
      a[k] = a[k - 1];
      a[k - 1] = tmp;
      --k;
    }
    ++j;
  }
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    oss << a[i];
  }
  return oss.str();
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    cout << solve(s) << '\n';
  }
  cout << endl;
  return 0;
}