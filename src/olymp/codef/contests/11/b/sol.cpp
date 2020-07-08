#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  cin >> x;
  x = abs(x);
  int cur = 0;
  int i = 0;
  while (true) {
    cur += i;
    if (x <= cur && x % 2 == cur % 2) {
      cout << i << endl;
      break;
    }
    ++i;
  }
  return 0;
}