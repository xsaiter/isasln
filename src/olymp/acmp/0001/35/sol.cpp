#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, n, m;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> n >> m;
    int d = 19 * m + (n + 239) * (n + 366) / 2;
    cout << d << "\n";
  }
  cout << endl;
  return 0;
}