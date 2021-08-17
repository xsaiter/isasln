#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> x(3);
    cin >> a >> b >> c;
    for (int i = 0; i < 3; ++i) {
      cin >> x[i];
    }
    sort(begin(x), end(x), less<int>());
  }
  return 0;
}