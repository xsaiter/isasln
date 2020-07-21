#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = (int)s.size();
  char a, b = 0, c = 1, d = 2;
  for (int i = 0; i < n; ++i) {
    a = s[i];
    if (!(a == b && b == c) && !(a == b && c == d)) {
      cout << a;
      d = c;
      c = b;
      b = a;
    }
  }
  cout << endl;
  return 0;
}