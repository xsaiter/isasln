#include <bits/stdc++.h>

using namespace std;

struct Res {
  char c;
  bool yes;
};

Res get_res(char x, char y) {
  Res res;
  if (x == 'A') {
    if (y == 'B') {
      res.c = 'C';
    } else if (y == 'C') {
      res.c = 'B';
    }
  } else if (x == 'B') {
    if (y == 'A') {
      res.c = 'C';
    } else if (y == 'C') {
      res.c = 'A';
    }
  } else if (x == 'C') {
    if (y == 'A') {
      res.c = 'B';
    } else if (y == 'B') {
      res.c = 'A';
    }
  }
  res.yes = true;
  return res;
}

Res search(const string &s) {
  if (s[0] == '?') {
    return get_res(s[1], s[2]);
  }
  if (s[1] == '?') {
    return get_res(s[0], s[2]);
  }
  if (s[2] == '?') {
    return get_res(s[0], s[1]);
  }
  Res res;
  res.yes = false;
  return res;
}

char solve(const string &a, const string &b, const string &c) {
  Res res = search(a);
  if (res.yes) {
    return res.c;
  }
  res = search(b);
  if (res.yes) {
    return res.c;
  }
  res = search(c);
  return res.c;
}

int main() {
  int t;
  cin >> t;   
  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << '\n';
  }
  cout << endl;
  return 0;
}