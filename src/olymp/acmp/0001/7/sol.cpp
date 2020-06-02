#include <bits/stdc++.h>

using namespace std;

int cmp(const string &a, const string &b) {
  auto na = a.size();
  auto nb = b.size();
  if (na > nb) {
    return -1;
  }
  if (na < nb) {
    return 1;
  }
  for (int i = 0; i < na; ++i) {
    if (a[i] > b[i]) {
      return -1;
    } else if (a[i] < b[i]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  string r;
  auto x = cmp(a, b);
  if (x == -1) {
    x = cmp(a, c);
    if (x == -1) {
      r = a;
    } else if (x == 1) {
      r = c;
    } else {
      r = a;
    }
  } else if (x == 1) {
    x = cmp(b, c);
    if (x == -1) {
      r = b;
    } else if (x == 1) {
      r = c;
    } else {
      r = b;
    }
  } else {
    x = cmp(a, c);
    if (x == 0) {
      r = a;
    } else if (x == -1) {
      r = a;
    } else {
      r = c;
    }
  }
  cout << r << endl;
  return 0;
}