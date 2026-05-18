#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cout << (n + 1 - i) << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}