#include <bits/stdc++.h>

using namespace std;

int get_pos(const string &s, int n, int prop) {
  int buf = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      buf = i;
      if (prop == 0) {
        return i;
      } else if (prop == 1) {
        --prop;
        buf = i;
      }
    }
  }
  return buf;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s >> t;
  sort(begin(s), end(s), [](auto x, auto y) { return x < y; });
  sort(begin(t), end(t), [](auto x, auto y) { return x > y; });
  int n = s.size();
  string res(n, '?');
  int i = 0, j = 0, k = 0;
  while (k < n) {
    if (k % 2 == 0) {
      int pos;
      if (s[i] > t[j]) {
        pos = get_pos(res, n, 1);
      } else {
        pos = get_pos(res, n, 0);
      }
      if (pos == -1)
        break;
      res[pos] = s[i];
      ++i;
    } else {
      int pos;
      if (s[i] > t[j]) {
        pos = get_pos(res, n, 1);
      } else {
        pos = get_pos(res, n, 0);
      }
      if (pos == -1)
        break;
      res[pos] = t[j];
      ++j;
    }
    ++k;
  }
  cout << res << endl;
  return 0;
}