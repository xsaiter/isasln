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
    int mi = min(a, b);
    int ma = max(a, b);    
    if (ma <= n) {
      int t = min(a, b);
      t += max(a, b);

    }
    cout << i << "\n";
  }
  cout << endl;
  return 0;
}