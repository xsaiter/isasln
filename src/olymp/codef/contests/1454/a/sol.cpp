#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
  for (int i = 1; i <= n; ++i) {
    int x = i + 1;
    if (x > n) x = 1;
    cout << x << " ";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
    cout << "\n";
  }
  cout << endl;
  return 0;
}