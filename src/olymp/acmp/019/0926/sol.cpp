#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int k = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 'C') {
        k += 1;
      }
    }
  }
  k /= 2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (k > 0) {
        cout << 1;
      } else {
        cout << 2;
      }
      if (a[i][j] == 'C') {
        k -= 1;
      }
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}

