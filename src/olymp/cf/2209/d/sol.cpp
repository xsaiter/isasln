#include <bits/stdc++.h>

using namespace std;

int choose(int &r, int &g, int &b, int a, int b) {
  
}

char to_c(int c) {
  if (c == 1) return 'R';
  if (c == 2) return 'G';
  return 'B';
}

string solve(int r, int g, int b) {
  ostringstream oss;
  while (true) {
    int c = choose(r, g, b);
    if (c == 0) {
      break;
    }
    oss << to_c(c);
  }
  return oss.str();
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int r, g, b;
    cin >> r >> g >> b;
    cout << solve(r, g, b) << '\n';
  }
  cout << endl;
  return 0;
}