#include <bits/stdc++.h>

using namespace std;

struct R {
  int n2;
  int n13;
};

int solve(const string &s) {
  int ans = 0;
  int n = (int)s.size();    
  vector<R> rr;
  bool beg = false;
  int n2 = 0, n13 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '4') {
      ans += 1;
      continue;
    }
    if (s[i] == '1' || s[i] == '3') {
      if (!beg) {
        beg = true;
        n12 += 1;
      } else {
        
      } // 111122
    } else if (s[i] == '2') {
      if (beg) {
      } else {}
    }
  }
  for(const auto &r : rr) {
    
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    cout << solve(s) << '\n';
  }
  cout << endl;
  return 0;
}