#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int tt;
  cin >> tt;
  for (int t = 0; t < tt; ++t) {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < k1; ++i) {
      int x;
      cin >> x;
      c1 = max(c1, x);
    }
    for (int i = 0; i < k2; ++i) {
      int x;
      cin >> x;
      c2 = max(c2, x);
    }
    cout << ((c1 > c2) ? "YES" : "NO") << endl;
  }
  return 0;
}