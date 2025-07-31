#include <bits/stdc++.h>

using namespace std;

const int MAXD = 10;

int di(char c) {
  return (int)c - (int)'0';
}

bool valid(const string &s, int n, int p, int q) {
  for (int i = 0; i < n; ++i) {
    if (i != p && i != q) {
      if (di(s[i]) != 0) {
        return true;
      }
      return true;
    }
  }
  return false;
}

int pos(const string &s, int n, vector<int> &v) {
  int mi = MAXD;
  int ans = -1;
  for (int i = n - 1; i >= 0; --i) {
    if (v.find(i) != v.end()) {
      int d = di(s[i]);
      if (d < mi) {
        mi = d;
        ans = i;
      }
    }
  }
  return ans;
}

vector<int> vec(int x) {
  vector<int> res {x};
  return res;
}

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  int p = pos(s, n, vec(-1));
  int q = pos(s, n, vec(p));
  while (!valid(s, n, p, q)) {
    vector<int> v {p, q};
    p = pos(s, n, v);
  }
  for (int i = 0; i < n; ++i) {
    if (i != p && i != q) {
      cout << s[i];
    }
  }
  cout << endl;
  return 0;
}