#include <bits/stdc++.h>

using namespace std;

struct Rec {
  string s;
  int d;
};

struct Interval {
  string a, b;
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<Rec> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].s >> a[i].d;
  }
  return 0;
}