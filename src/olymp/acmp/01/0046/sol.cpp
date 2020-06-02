#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s = "2.7182818284590452353602875";
  if (n > 0) {
    cout << s.substr(0, 2) + s.substr(2, n) << endl;
  } else {
    cout << "3" << endl;
  }
  fflush(stdout);
  return 0;
}