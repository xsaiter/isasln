#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<string> &a) {
  int ans = 0;
  set<pair<int, int>> ss;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (a[i].size() == a[j].size() + a[k].size()) {
          string s = a[j] + a[k];
          if (a[i] == s) {
            pair<int, int> p(min(j, k), max(j, k));
            if (!ss.contains(p)) {
              ss.insert(p);
              ++ans;
            }            
          } else {
            s = a[k] + a[j];
            if (a[i] == s) {                          
              pair<int, int> p(min(j, k), max(j, k));
              if (!ss.contains(p)) {
                ss.insert(p);
                ++ans;
              }            
            }
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  vector<string> a;
  while (true) {
    string s;
    cin >> s;
    if (s == "ENDOFINPUT") {
      break;
    }
    a.push_back(s);
  }
  int n = (int)a.size();
  int ans = solve(n, a);
  cout << ans << endl;
  return 0;
}