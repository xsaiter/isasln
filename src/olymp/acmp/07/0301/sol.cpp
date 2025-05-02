#include <bits/stdc++.h>

using namespace std;

struct R {
  string a, b;
};

int value_b(int s, int k, int pos, int cb) {
  int start = 0;
  if (pos == 1) {
    start = 1;
  }  
  for (int i = start; i <= 9; ++i) {
    if (s - cb - i <= (k - pos) * 9) {
      return i;
    }    
  }
  throw("unreachable code");
}

int value_a(int s, int ca) {
  return min(s - ca, 9);
}

R solve(int s, int k) {
  ostringstream osa;
  ostringstream osb;
  
  int ca = 0, cb = 0;   
  for (int i = 1; i <= k; ++i) {
    int v = value_a(s, ca);
    ca += v;
    osa << v;
        
    v = value_b(s, k, i, cb);
    cb += v;
    osb << v;
  }

  return R { .a = osa.str(), .b = osb.str() };
}

int main() {
  int s, k;
  cin >> s >> k;
  R r = solve(s, k);
  cout << r.a << ' ' << r.b << endl;
  return 0;
}