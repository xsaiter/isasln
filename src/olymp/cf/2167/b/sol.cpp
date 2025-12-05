#include <bits/stdc++.h>

using namespace std;

int ord(char c) {
  return (int)c - (int)'a';
}

bool solve(int n, string &s, string &t) {  
  vector<int> a(27);
  for (int i = 0; i < n; ++i) {
    a[ord(s[i])] += 1;
    a[ord(t[i])] -= 1;
  }
  for (const auto& x : a) {
    if (x != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    cout << (solve(n, s, t) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}