#include <bits/stdc++.h>

using namespace std;

int solve(string &s) {
  int res = 1;
  int n = (int)s.size();
  set<int> cc;
  for (int i = 0; i < n; ++i) {
    int c = (int)s[i];
    auto it = cc.find(c);
    if (it == cc.end()) {
      if ((int)cc.size() == 3) {
        ++res;
        cc.clear();
        cc.insert(c);
      } else {
        cc.insert(c);
      }
    }   
  }  
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << '\n';
  }
  cout << endl;
  return 0;
}
