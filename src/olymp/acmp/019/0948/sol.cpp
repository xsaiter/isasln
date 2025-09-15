#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, n;
  cin >> k >> n;
  int a, b;
  if (k >= n) {
    a = 1; b = n;
  } else {
    if (k == 1) {
      a = n / k;
      b = 1;
    } else {
      b = n % k;
      if (b == 0) {
        b = k;
        a = n / k;
      } else {
        a = (n - b) / k + 1;
      }
    }
  }
  cout << a << ' ' << b << endl;
  return 0;
}