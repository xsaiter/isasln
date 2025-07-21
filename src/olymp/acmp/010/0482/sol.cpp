#include <bits/stdc++.h>

using namespace std;

const int N = 32768;

string to_str(int k) {
  return to_string(k);
}

int to_dig(char c) {
  return (int)c - (int)'0';
}

void add(vector<int> &a, int j) {
  string s = to_str(j);
  int len = (int)s.size();
  for (int i = 0; i < len; ++i) {
    int d = to_dig(s[i]);
    a.push_back(d);
  }
}

int solve(int n) {
  vector<int> a;
  a.push_back(-1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      add(a, j);
      if (a.size() >= N) {
        break;
      }
    }    
  }
  return a[n];
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}