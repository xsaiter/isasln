#include <bits/stdc++.h>

using namespace std;
using ui = unsigned int;

int main() {
  constexpr ui expected_len = 5;
  string s;
  cin >> s;
  const ui len = s.size();
  if (len != expected_len || s[2] != '-' || s[0] < 'A' || s[0] > 'H' ||
      s[3] < 'A' || s[3] > 'H' || s[1] < '1' || s[1] > '8' || s[4] < '1' ||
      s[4] > '8') {
    cout << "ERROR";
  } else {
    auto w = abs(s[0] - s[3]);
    auto h = abs(s[1] - s[4]);
    if ((w == 2 && h == 1) || (w == 1 && h == 2)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
  cout << endl;
  return 0;
}