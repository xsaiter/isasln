#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int x = s[0] - 'A';
  int y = s[1] - '1';
  if ((x + y) % 2 != 0) {
    cout << "WHITE";
  } else {
    cout << "BLACK";
  }
  cout << endl;
  return 0;
}