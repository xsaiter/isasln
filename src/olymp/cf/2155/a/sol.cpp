#include <bits/stdc++.h>

using namespace std;

int calc(int n) {
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }
  if (n % 2 == 0) {
    return n / 2 + calc(n / 2);
  }
  return (n - 1) / 2 + calc((n - 1) / 2 + 1);
}

int solve(int n) {
  return 2 * calc(n);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << solve(n) << '\n';
  }
  cout << endl;
  return 0;
}
