#include <bits/stdc++.h>

using namespace std;

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
    sort(begin(a), end(a), greater<int>());
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
  cout << endl;
  return 0;
}