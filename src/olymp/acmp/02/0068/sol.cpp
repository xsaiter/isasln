#include <bits/stdc++.h>

using namespace std;

bool solve(int a, int x) {
  if (a == 0) {
    return (x % 2 == 1);
  }
  return (x % 2 == 1);
}

int main() {
  string s;
  cin >> s;
  int a = (s == "Home") ? 0 : 1;
  int x;
  cin >> x;
  cout << (solve(a, x) ? "Yes" : "No") << endl;
  return 0;
}