#include <bits/stdc++.h>

using namespace std;

struct Rec {
  char c;
  int v;
};

int solve(int n, const vector<Rec> &a) {
  int res = 0;
  int cur = 0;
  int len = 0;
  bool state = false;    
  for (int i = 0; i < n; ++i) {    
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<Rec> a(n);
  for (int i = 0; i < n; ++i) {    
    Rec r;
    cin >> r.c >> r.v;    
    a[i] = r;    
  }
  cout << solve(n, a) << endl;
  return 0;
}