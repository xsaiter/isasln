#include <bits/stdc++.h>

using namespace std;

int solve(const string &s, int k) {
  int l, r;
  l = r = k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = (int)s.size();
  for (int k = 0; k < n; ++k) {
    cout << (solve(s, k) == 0 ? "Mike" : "Ann") << "\n";
  }
  cout << endl;
  return 0;
}