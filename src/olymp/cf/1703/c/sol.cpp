#include <bits/stdc++.h>

using namespace std;

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
    vector<pair<int, string>> b(n);
    for (int i = 0; i < n; ++i) {
      int k; cin >> k;
      string s; cin >> s;
      b[i] = make_pair(k, s);
    }
    for (int i = 0; i < n; ++i) {      
      for (int j =  b[i].first - 1; j >= 0; --j) {
        char c = b[i].second[j];
        if (c == 'D') {
          if (a[i] == 9) {
            a[i] = 0;
          } else {
            ++a[i];
          }
        } else {
          if (a[i] == 0) {
            a[i] = 9;
          } else {
            --a[i];
          }
        }
      }
    }
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
  cout << endl;
  return 0;
}