#include <bits/stdc++.h>

using namespace std;

string solve(const string &s, int len, int n) {    
  string res(n, '0');  
  for (int i = 0; i < len; i += 2) {
    res[i / 2] = s[i];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int len = 2 * n - 1;
    string s;
    cin >> s;
    cout << solve(s, len, n) << "\n";
  }
  cout << endl;
  return 0;
}

