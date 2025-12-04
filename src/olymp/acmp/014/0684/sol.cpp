#include <bits/stdc++.h>

using namespace std;

struct C {
  int x, y;
  C(int x_, int y_) : x(x_), y(y_) {}
};

C parse_c(const string &s) {
  int x = ((int)s[0] - (int)'a') + 1;
  int y = ((int)s[0] - (int)'0');
  return C(x, y);
}

C read_c() {
  string s;
  cin >> s;
  return parse_c(s);

}

bool solve(const C &a, const C &b) {
  return false;
}

int main() {
  C a = read_c();
  C b = read_c();
  cout << (solve(a, b) ? "YES" : "NO") << endl;
  return 0;
}
