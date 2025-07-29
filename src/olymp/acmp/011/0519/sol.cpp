#include <bits/stdc++.h>

using namespace std;

void pre_min(string &s, int n) {
  if (s[0] != '0') {
    return;
  }
  for (int i = 1; i < n; ++i) {
    if (s[i] != '0') {
      swap(s[0], s[i]);
      break;
    }
  }
}

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  sort(begin(s), end(s), less<char>());
  pre_min(s, n);  
  cout << s << ' ';
  sort(begin(s), end(s), greater<char>());
  cout << s << endl;
  return 0;
}