#include <bits/stdc++.h>

using namespace std;

int solve(int s, int t) {
  int ans = 0;
  while (s != t) {
    if (s == 12) {
      s = 1;
    } else {
      ++s;
    }
    ++ans;
  }
  return ans;
}

int main() {
  int s, t;
  cin >> s >> t;
  cout << solve(s, t) << endl;
  return 0;
}