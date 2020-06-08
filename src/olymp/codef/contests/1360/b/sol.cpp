#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    sort(begin(s), end(s));
    int md = 1 << 10;
    for (int i = 1; i < n; ++i) {
      int d = abs(s[i] - s[i - 1]);
      if (d < md) {
        md = d;
      }
    }
    printf("%d\n", md);
  }
  return 0;
}