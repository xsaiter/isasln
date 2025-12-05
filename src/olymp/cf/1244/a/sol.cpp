#include <bits/stdc++.h>

using namespace std;

int calc(int a, int c) {
  int x = 1;
  if (a > c) {
    int rem = a % c;
    if (rem == 0) x = a / c;
    else x = (a - rem) / c + 1;
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = calc(a, c);
    int y = calc(b, d);
    if (x + y <= k) { cout << x << " " << y; }
    else { cout << "-1"; }
    cout << "\n";
  }
  cout << endl;
  return 0;
}