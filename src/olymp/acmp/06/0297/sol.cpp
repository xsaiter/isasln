#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' || s[i] == '6' || s[i] == '9') {
      k += 1;
    } else if (s[i] == '8') {
      k += 2;
    }
  }
  cout << k << endl;
  return 0;
}