#include <bits/stdc++.h>

using namespace std;

string solve(int k) {
  string s = "GCV";
  for (int i = 0; i < k; ++i) {
    swap(s[1], s[2]);
    swap(s[0], s[1]);
  }
  return s;
}

int main() {
  int k;
  cin >> k;
  cout << solve(k) << endl;
  return 0;
}