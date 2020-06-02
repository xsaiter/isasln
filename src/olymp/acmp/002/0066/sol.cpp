#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  char c;
  cin >> c;
  string s = "qwertyuiopasdfghjklzxcvbnm";
  const int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == c) {
      c = ((i + 1) == n) ? s[0] : s[i + 1];
      break;
    }
  }
  cout << c << endl;
  return 0;
}