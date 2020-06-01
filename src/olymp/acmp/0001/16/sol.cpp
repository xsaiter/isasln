#include <bits/stdc++.h>

using namespace std;

int rec(int k, int p) {
  if (p == 0) {
    return 1;
  }
  int res = 0;
  for (int i = 1; i < k; ++i) {
    if (p - i < 0) {
      break;
    }
    res += rec(i, p - i);
  }
  return res;
}

int main() {
  int n;
  cin >> n;  
  int res = rec(n + 1, n);
  printf("%d", res);
  return 0;
}