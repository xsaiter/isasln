#include <bits/stdc++.h>

using namespace std;

void solve(string &s, int n, int k) {
  map<char, vector<int>> m;
  for (int i = 0; i < n; ++i) {
    auto it = m.find(s[i]);
    if (it != s.end()) {
      
    }
  }
  int a = (int)'a';
  int z = (int)'z';
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  solve(s, n, k);
  cout << s << endl;
  return 0;
}