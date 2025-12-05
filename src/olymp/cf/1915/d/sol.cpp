#include <bits/stdc++.h>

using namespace std;

bool is_c(char c) {
  return c == 'b' || c == 'c' || c == 'd';
}

bool is_v(char c) {
  return c == 'a' || c == 'e';
}

// cv || cvc
string solve(const string &s, int n) {
  ostringstream oss;
  bool is_prev_c = false;
  bool is_prev_v = false;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (is_c(c)) {
      is_prev_c = true;
      is_prev_v = false;
    } else if (is_v(c)) {
      if (is_prev_c) {
        ++i;
      }
      is_prev_c = false;
      is_prev_v = true;
    }
  }
  return oss.str();
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s, n) << '\n';
  }
  cout << endl;
  return 0;
}
