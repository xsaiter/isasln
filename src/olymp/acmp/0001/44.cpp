#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;

  string r = ">>-->";
  string l = "<--<<";

  const size_t n = s.size();
  const size_t nr = r.size();
  const size_t nl = l.size();

  int res = 0, i, j;

  for (i = 0; i < n; ++i) {
    for (j = 0; j < nr; ++j) {
      if (s[i + j] != r[j]) {
        break;
      }
    }
    if (j == nr) {
      ++res;
    }
    for (j = 0; j < nl; ++j) {
      if (s[i + j] != l[j]) {
        break;
      }
    }
    if (j == nl) {
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}