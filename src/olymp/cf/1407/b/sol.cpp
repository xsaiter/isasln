#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, vector<int> &a) {
  vector<int> b;
  return b;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b = solve(n, a);
    for (int i = 0; i < (int)b.size(); ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}