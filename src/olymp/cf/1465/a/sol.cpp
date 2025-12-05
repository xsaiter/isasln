#include <bits/stdc++.h>

using namespace std;

bool solve(string &s, int n) {
  int x = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ')') {
      ++x;
    } else {
      break;
    }
  }
  if (x > n - x) return true;
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << (solve(s, n) == true ? "Yes" : "No") << endl;
  }
  return 0;
}