#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << solve(a, b) << endl;
  return 0;
}