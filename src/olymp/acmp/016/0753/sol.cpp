#include<bits/stdc++.h>

using namespace std;

const int N = 26;

int code_of(char c) {
  return (int)c - (int)'a';
}

int solve(const string &s, int n) {  
  vector<vector<int>> t(N, vector<int>());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int ci = code_of(s[i]);
      int cj = code_of(s[j]);
    }    
  }
  return 0;
}

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  cout << solve(s, n) << endl;
  return 0;
}