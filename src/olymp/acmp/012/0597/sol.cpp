#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &r) {
  return r[0] >= r[1] + r[2];
}

int main() {
  vector<int> r(3);
  cin >> r[0] >> r[1] >> r[2];
  cout << (solve(r) ? "YES" : "NO") << endl;
  return 0;
}