#include <bits/stdc++.h>

using namespace std;

bool s_good(const std::string &s) {
  int k = 0;
  const int len = s.size();
  for (char c : s) {
    if (c == '1') {
      ++k;
    }
  }
  return k > 0 && (len % k) == 0;
}

int main() {
  std::string s;
  getline(cin, s);
  vector<int> p;
  p.push_back(0);
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    int v = s[i] - '0';
    p.push_back(p.back() + v);
  }
  // getline(cin, si);
  return 0;
}