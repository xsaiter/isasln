#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = (n == 2) ? 2 : (n % 2);  
    cout << x << "\n";
  }
  cout << endl;
  return 0;
}