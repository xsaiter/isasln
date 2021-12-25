#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &a, int n, int k) {
  if (n - k < 3) return false;
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool can = solve(a, n, k);
    if (can) {
      cout << "-1";
    } else {
      copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}