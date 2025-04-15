#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n) {
  vector<int> a(n);
  return a;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a = solve(n);
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
  }
  cout << endl;
  return 0;
}