#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> &b, int k) {
  return 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int k = n * m;
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
      cin >> b[i];
    }
    cout << solve(b, k) << '\n';
  }
  cout << endl;
  return 0;
}