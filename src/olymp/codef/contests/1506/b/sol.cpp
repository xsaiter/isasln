#include <bits/stdc++.h>

using namespace std;

int find_next_pos(string &s, int n, int k, int start) {
  int j = start + 1;
  int res = j;
  while (j < n && j - start <= k) {
    if (s[j] == '*') {
      res = j;
    }
    ++j;
  }
  return res;
}

int solve(string &s, int n, int k) {    
  int res = 0;
  int i = 0; 
  while (i < n) {
    if (s[i] == '*') {
      ++res;
      i = find_next_pos(s, n, k, i);
    } else {
      ++i;
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {        
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << solve(s, n, k) << "\n";
  }
  cout << endl;
  return 0;
}