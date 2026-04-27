#include <bits/stdc++.h>

using namespace std;

vector<string> solve(int n, int k) {
  vector<string> a;
  return a;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a = solve(n, k);
    if (a.empty()) {
      cout << "NO";
    } else {
      cout << "YES";
      for (int i = 0; i < n; ++i) {
        cout << '\n' << a[i];
      }
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}