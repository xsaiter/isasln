#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string b;
    cin >> b;
    int n = (int)b.size();
    for (int i = 0; i < n; i += 2) {
      cout << b[i];
    }
    cout << b[n - 1] << "\n";
  }
  cout << endl;
  return 0;
}