#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b, n;
    cin >> a >> b >> n;
    int i = 0;
    while (max(a, b) <= n) {
      if (a < b) { a += b; } 
      else { b += a; }
      ++i;
    }
    cout << i << "\n";
  }
  cout << endl;
  return 0;
}