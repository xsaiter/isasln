#include <bits/stdc++.h>

using namespace std;

bool solve(int n, vector<int> &a) {
  return false;
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
    bool can = solve(n, a);
    if (can) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}