#include <bits/stdc++.h>

using namespace std;

string solve(const string &s, int n) {
  int one = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'n')
      ++one;
  }
  int zero = (n - one * 3) / 4;
  ostringstream os;
  while (one--) {
    os << "1"
       << " ";
  }
  while (zero--) {
    os << "0"
       << " ";
  }
  return os.str();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << solve(s, n) << endl;
  return 0;
}