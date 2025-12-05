#include <bits/stdc++.h>

using namespace std;

int num(char d) { return (int)d - (int)'0'; }

string solve(string &s, int n) {
  string no = "-1";
  int sum_all = 0;
  for (int i = 0; i < n; ++i) {
    sum_all += num(s[i]);
  }
  int pos_beg = 0;
  int pos_end = n - 1;
  if (sum_all % 2 == 0 && num(s[pos_end]) % 2 != 0) {
    return s;
  }
  while (pos_beg <= pos_end) {
    if (num(s[pos_end]) % 2 != 0) {
      break;
    }
    sum_all -= num(s[pos_end]);
    --pos_end;
  }
  if (pos_beg > pos_end) {
    return no;
  }
  int last = pos_end;
  --pos_end;
  if (pos_beg > pos_end) {
    return no;
  }
  if (sum_all % 2 == 0) {
    return s.substr(pos_beg, pos_end - pos_beg + 1) + s[last];
  }
  while (pos_beg <= pos_end) {
    if (num(s[pos_end]) > 0 && num(s[pos_end]) % 2 != 0) {
      return s.substr(pos_beg, pos_end - pos_beg) + s[last];
    }
    --pos_end;
  }
  return no;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s, n) << "\n";
  }
  cout << endl;
  return 0;
}