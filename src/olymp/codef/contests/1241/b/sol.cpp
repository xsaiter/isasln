#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    set<char> ss(s.begin(), s.end());
    set<char> tt(t.begin(), t.end());
    set<char> res;
    set_intersection(ss.begin(), ss.end(), tt.begin(), tt.end(), inserter(res, res.begin()));
    cout << ((res.size() == 0) ? "NO" : "YES") << "\n";
  }
  cout << endl;
  return 0;
}