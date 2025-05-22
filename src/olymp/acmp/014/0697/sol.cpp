#include <bits/stdc++.h>

using namespace std;

int main() {
  int l, w, h;
  cin >> l >> w >> h;
  int s = 2 * (l * h + w * h);
  int rem = s % 16;
  int ans = (s - rem) / 16;
  if (rem > 0) {
    ans += 1;
  }
  cout << ans << endl;
  return 0;
}