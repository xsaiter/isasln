#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  bitset<sizeof(int) * 8> bb(n);
  int k = bb.count();
  return n + k;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}