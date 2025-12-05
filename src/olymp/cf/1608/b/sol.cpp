#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int a, int b, vector<int> &res) {
  if (a == n || b == n) {
    return false;
  }
  if (a + b + 2 > n) {
    return false;
  }
  if (abs(a - b) > 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {    
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> res(n);
    bool b = solve(n, a, b, res);
    if (b) {
      cout << "-1";
    } else {
      for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
      }
    }
    cout << "\n";
  }
  cout << endl;
  return 0;
}
