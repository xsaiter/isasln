#include <bits/stdc++.h>

using namespace std;

const int N = 512;

int main() {
  string s;
  cin >> s;  
  int m = (int)s.size();
  int c = N, h = N, l = N;
  for (int i = 0; i < m; ++i) {
    if (s[i] == '1') {
      ++c;
      h = max(h, c);
    } else {
      --c;
      l = min(l, c);
    }
  }  
  cout << (h - l + 1) << endl;
  return 0;
}