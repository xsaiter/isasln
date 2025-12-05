#include <bits/stdc++.h>

using namespace std;

void solve(const vector<int> &a, int n) {
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      cout << 1 << "\n" << i + 1 << "\n";
      return;
    } else {
      if (j == -1) {
        j = i;
      } else {
        cout << 2 << "\n" << j + 1 << " " << i + 1 << "\n";
        return;
      }
    }
  }
  cout << "-1" << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }    
    solve(a, n);
  }
  cout << endl;
  return 0;
}