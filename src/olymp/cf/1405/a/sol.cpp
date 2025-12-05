#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    reverse(begin(p), end(p));
    copy(begin(p), end(p), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
  cout << endl;
  return 0;
}